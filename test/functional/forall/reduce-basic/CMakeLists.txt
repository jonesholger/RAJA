###############################################################################
# Copyright (c) 2016-20, Lawrence Livermore National Security, LLC
# and RAJA project contributors. See the RAJA/COPYRIGHT file for details.
#
# SPDX-License-Identifier: (BSD-3-Clause)
###############################################################################

#
# List of reduction types for generating test files.
#
set(REDUCETYPES ReduceSum ReduceMin ReduceMax ReduceMinLoc ReduceMaxLoc)


#
# Generate tests for each enabled RAJA back-end
#
# Note: FORALL_BACKENDS is defined in ../CMakeLists.txt
#
foreach( BACKEND ${FORALL_BACKENDS} )
  foreach( REDUCETYPE ${REDUCETYPES} )
    configure_file( test-forall-basic-reduce.cpp.in
                    test-forall-basic-${REDUCETYPE}-${BACKEND}.cpp )
    raja_add_test( NAME test-forall-basic-${REDUCETYPE}-${BACKEND}
                   SOURCES ${CMAKE_CURRENT_BINARY_DIR}/test-forall-basic-${REDUCETYPE}-${BACKEND}.cpp )

    target_include_directories(test-forall-basic-${REDUCETYPE}-${BACKEND}.exe
                               PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tests)
  endforeach()
endforeach()

unset( REDUCETYPES )
