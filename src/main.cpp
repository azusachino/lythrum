#include <iostream>
#include <rocksdb/db.h>
#include "compaction_tester.h"

int main() {
    // Initialize RocksDB
    rocksdb::Options options;
    options.create_if_missing = true;

    rocksdb::DB* db;
    rocksdb::Status status = rocksdb::DB::Open(options, "testdb", &db);
    if (!status.ok()) {
        std::cerr << "Unable to open RocksDB: " << status.ToString() << std::endl;
        return 1;
    }

    // Create a CompactionTester instance
    CompactionTester tester(db);

    // Run tests for different compaction modes
    tester.initialize();
    tester.runTests();
    tester.reportResults();

    // Clean up
    delete db;
    return 0;
}