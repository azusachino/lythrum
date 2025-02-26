#ifndef COMPACTION_TESTER_H
#define COMPACTION_TESTER_H

#include <rocksdb/db.h>
#include <string>
#include <vector>

class CompactionTester {
public:
    CompactionTester(const std::string& dbPath);
    ~CompactionTester();

    void initialize();
    void runTests();
    void reportResults();

private:
    std::string dbPath;
    rocksdb::DB* db;
    std::vector<std::string> compactionModes;
    std::vector<double> performanceMetrics;

    void setupCompactionMode(const std::string& mode);
    void collectMetrics();
};

#endif // COMPACTION_TESTER_H