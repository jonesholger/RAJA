/*!
 ******************************************************************************
 *
 * \file
 *
 * \brief   Header file for RAJA algorithm definitions.
 *
 *          Definitions in this file will propagate to all RAJA header files.
 *
 ******************************************************************************
 */

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2016-20, Lawrence Livermore National Security, LLC
// and RAJA project contributors. See the RAJA/COPYRIGHT file for details.
//
// SPDX-License-Identifier: (BSD-3-Clause)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

#ifndef RAJA_pattern_detail_algorithm_HPP
#define RAJA_pattern_detail_algorithm_HPP

#include "camp/helpers.hpp"

namespace RAJA
{

namespace detail
{


template <typename Iter>
using IterVal = camp::decay<decltype(*camp::val<Iter>())>;

template <typename Container>
using ContainerVal =
    camp::decay<decltype(*camp::val<camp::iterator_from<Container>>())>;

RAJA_INLINE
int firstIndex(int n, int p, int pid)
{
  return (static_cast<size_t>(n) * pid) / p;
}

}  // end namespace detail

}  // end namespace RAJA

#endif