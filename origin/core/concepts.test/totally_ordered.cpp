// Copyright (c) 2009-2015 Andrew Sutton
// All rights reserved

#include <origin/generic.hpp>

struct S0 { };

struct S1 
{
  bool operator==(S1) const;
  bool operator<(S1) const;
};

struct S2
{
  bool operator==(S2) const;
  bool operator!=(S2) const;
  bool operator<(S2) const;
  bool operator>(S2) const;
  bool operator<=(S2) const;
  bool operator>=(S2) const;
};

static_assert(origin::Totally_ordered<int>(), "");
static_assert(origin::Totally_ordered<float>(), "");
static_assert(not origin::Totally_ordered<S0>(), "");
static_assert(not origin::Totally_ordered<S1>(), "");
static_assert(origin::Totally_ordered<S2>(), "");

static_assert(origin::Totally_ordered<int, long>(), "");
static_assert(not origin::Totally_ordered<int, S0>(), "");

int main() { return 0; }
