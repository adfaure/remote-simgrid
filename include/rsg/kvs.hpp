/* Copyright (c) 2015. The SimGrid Team. All rights reserved.              */

/* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU Affero Licence (see in file LICENCE).        */

#ifndef SRC_RSG_KVS_HPP_
#define SRC_RSG_KVS_HPP_

#include <string>
#include <vector>

namespace simgrid {
  namespace rsg {
    namespace kvs {

      void get(std::string& _return, const std::string& key);
      /** Retrieve a list of value based on a prematch pattern 
        * It allows to create sub-key hierachi in your datal.
        * For example: mykey/mysubkey
        * Then you can use prematch to get all key with getprematch("mykey").
        * There is no assumption about the delimiter you can use, so there are some valid examples.
        */
      std::vector<std::string> getprematch(const std::string& key);
      void remove(const std::string& key);
      void replace(const std::string& key, const std::string& data);
      void insert(const std::string& key, const std::string& data);

    } //namespace kvs
  } //namespace rsg
} // namespace simgrid

#endif /* SRC_RSG_KVS_HPP_ */
