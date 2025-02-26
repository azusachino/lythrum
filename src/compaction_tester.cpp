#include <iostream>
#include <rocksdb/db.h>
#include <rocksdb/options.h>
#include "compaction_tester.h"
#include "utils/benchmark_utils.h"

CompactionTester::CompactionTester(const std::string& db_path) : db_path_(db_path) {}

void CompactionTester::initialize() {
    rocksdb::Options options;
    options.create_if_missing = true;
    options.max_open_files = 100;

    // Initialize the database
    rocksdb::Status status = rocksdb::DB::Open(options, db_path_, &db_);
    if (!status.ok()) {
        std::cerr << "Unable to open RocksDB: " << status.ToString() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void CompactionTester::runTests() {
    // Test different compaction modes
    std::vector<rocksdb::CompactionStyle> compaction_styles = {
        rocksdb::kCompactionStyleLevel,
        rocksdb::kCompactionStyleUniversal,
        rocksdb::kCompactionStyleFIFO
    };

    for (const auto& style : compaction_styles) {
        rocksdb::Options options;
        options.compaction_style = style;

        // Reopen the database with the new options
        rocksdb::Status status = rocksdb::DB::Open(options, db_path_, &db_);
        if (!status.ok()) {
            std::cerr << "Unable to open RocksDB with compaction style: " << style << " - " << status.ToString() << std::endl;
            continue;
        }

        // Perform write and read operations to test performance
        startTimer();
        for (int i = 0; i < 10000; ++i) {
            db_->Put(rocksdb::WriteOptions(), std::to_string(i), "value" + std::to_string(i));
        }
        stopTimer();

        reportResults(style);
        delete db_;
    }
}

void CompactionTester::reportResults(rocksdb::CompactionStyle style) {
    // Log the results of the test
    std::cout << "Compaction style: " << style << " completed." << std::endl;
}

CompactionTester::~CompactionTester() {
    delete db_;
}