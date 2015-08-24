/* Copyright (c) 2006-2015. The SimGrid Team. All rights reserved.          */

/* This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL) which comes with this package. */

#ifndef SIMGRID_RSG_MAILBOX_HPP
#define SIMGRID_RSG_MAILBOX_HPP

#include <boost/unordered_map.hpp>

#include "actor.hpp"

namespace simgrid {
namespace rsg {

class Comm;

/** @brief Mailboxes
 *
 * Rendez-vous point for network communications, similar to URLs on which you could post and retrieve data.
 * They are not network locations: you can post and retrieve on a given mailbox from anywhere on the network.
 * You can access any mailbox without any latency. The network delay are only related to the location of the
 * sender and receiver.
 */
class Mailbox {
	friend Comm;

private:
	Mailbox(const char*name, void* remoteAddr);
public:
	~Mailbox();
	
//protected:
	void *getRemote() { return p_remoteAddr; }

public:
	/** Retrieve the mailbox associated to the given string */
	static Mailbox *byName(const char *name);

private:
	std::string p_name;
	void *p_remoteAddr = NULL;
	static boost::unordered_map<std::string, Mailbox *> *mailboxes;
};
}} // namespace simgrid::rsg

#endif /* SIMGRID_RSG_MAILBOX_HPP */