#if !defined(VMD_TO_DATA_HPP)
#define VMD_TO_DATA_HPP

#include "detail/vmd_detail_setup.hpp"

#if BOOST_VMD_VARIADICS

#if BOOST_VMD_PPLIB
#include "vmd_to_data_pplib.hpp"
#else
#include "vmd_to_data_native.hpp"
#endif /* BOOST_VMD_PPLIB */

#endif /* BOOST_VMD_VARIADICS */
#endif /* VMD_TO_DATA_HPP */