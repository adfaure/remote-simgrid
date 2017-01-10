#include "rsg/kvs.hpp"
#include "RsgClient.hpp"

using namespace ::simgrid::rsg;


void kvs::get(std::string& _return, const std::string& key) {
  client->kvs->get(_return, key);
}

std::vector<std::string> kvs::getprematch(const std::string& key) {
  std::vector<std::string> _return;
  client->kvs->getprematch(_return, key);
/**
 * This c++11 it seems okay to return a local variable because it should be moved, otherwise it could lead to performances issues.
 * An deeper investigation could be a good idea.
 */
  return _return;
}

void kvs::remove(const std::string& key) {
  client->kvs->remove(key);
}

void kvs::replace(const std::string& key, const std::string& data) {
  client->kvs->replace(key, data);
}

void kvs::insert(const std::string& key, const std::string& data) {
  client->kvs->insert(key, data);
}
