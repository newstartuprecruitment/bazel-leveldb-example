#include <cassert>
#include <iostream>

#include "leveldb/db.h"
#include "leveldb/write_batch.h"

using namespace std;

class LocalLevelDb {
 public:
  LocalLevelDb() {
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
    assert(status.ok());
  }

  string get(string k) {
    leveldb::ReadOptions readOptions;
    leveldb::Slice key = k;
    string value;
    db->Get(readOptions, key, &value);
    return value;
  }

  void getBatch(string keyPrefix) {
    int l = keyPrefix.size();
    string limit(1, keyPrefix.at(l - 1) + 1);
    limit = keyPrefix.substr(0, l - 1) + limit;
    leveldb::Iterator *it = db->NewIterator(leveldb::ReadOptions());
    for (it->Seek(keyPrefix); it->Valid() && it->key().ToString() < limit;
         it->Next()) {
      std::cout << it->key().ToString() << " " << it->value().ToString()
                << "\n";
    }
  }

  void getAll() {
    leveldb::Iterator *it = db->NewIterator(leveldb::ReadOptions());
    for (it->SeekToFirst(); it->Valid(); it->Next()) {
      std::cout << it->key().ToString() << " " << it->value().ToString()
                << "\n";
    }
  }

  void add(string k, string v) {
    leveldb::WriteOptions writeOptions;
    leveldb::Slice key = k;
    leveldb::Slice value = v;
    db->Put(writeOptions, key, value);
  }

  void deleteBatch(string keyPrefix) {
    int l = keyPrefix.size();
    string limit(1, keyPrefix.at(l - 1) + 1);
    limit = keyPrefix.substr(0, l - 1) + limit;
    leveldb::WriteBatch batch;
    leveldb::Iterator *it = db->NewIterator(leveldb::ReadOptions());
    for (it->Seek(keyPrefix); it->Valid() && it->key().ToString() < limit;
         it->Next()) {
      batch.Delete(it->key());
    }
    db->Write(leveldb::WriteOptions(), &batch);
  }

 private:
  leveldb::DB *db;
};

int main() {
  LocalLevelDb db;
  db.add("k1-1", "v1");
  db.add("k1-2", "v2");
  db.add("k2-1", "v1");
  db.getBatch("k1");
  db.deleteBatch("k1");
  db.getAll();

  return 0;
}