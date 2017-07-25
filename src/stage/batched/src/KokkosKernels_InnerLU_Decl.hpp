#ifndef __KOKKOSKERNELS_INNER_LU_DECL_HPP__
#define __KOKKOSKERNELS_INNER_LU_DECL_HPP__


/// \author Kyungjoo Kim (kyukim@sandia.gov)

namespace KokkosKernels {
  namespace Batched {
    namespace Experimental {
      template<int bmn>
      struct InnerLU {
        const int _as0, _as1;
    
        KOKKOS_INLINE_FUNCTION
        InnerLU(const int as0, const int as1) 
          : _as0(as0), _as1(as1) {}
    
        // lu
        template<typename ValueType>
        KOKKOS_INLINE_FUNCTION
        int serial_invoke(ValueType *__restrict__ A);

        // for remainder square
        template<typename ValueType>
        KOKKOS_INLINE_FUNCTION
        int serial_invoke(const int m, 
                          ValueType *__restrict__ A);
    
        // for remainder
        template<typename ValueType>
        KOKKOS_INLINE_FUNCTION
        int serial_invoke(const int m, const int n,
                          ValueType *__restrict__ A);
      };
    }
  }
}
#endif
