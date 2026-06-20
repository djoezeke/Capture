/**
 * @file capture/uncapture.h
 */

#ifndef DJOEZEKE_RECAPTURE_H
#define DJOEZEKE_RECAPTURE_H

//-----------------------------------------------------------------------------
// [SECTION] Capture General Cleanup
//-----------------------------------------------------------------------------

#if 1 // def MACRO

#undef CAPTURE_UNUSED
#undef CAPTURE_RESTRICT
#undef CAPTURE_HAS_BUILTIN
#undef CAPTURE_DEPRECATED
#undef CAPTURE_UNUSED
#undef CAPTURE_INLINE
#undef CAPTURE_FORCE_INLINE
#undef CAPTURE_NODISCARD
#undef CAPTURE_NORETURN
#undef CAPTURE_FALLTHROUGH
#undef CAPTURE_ALLOC_SIZE
#undef CAPTURE_ALLOC_SIZE2
#undef CAPTURE_ALIGNED

#endif // MACRO

//-----------------------------------------------------------------------------
// [SECTION] User's General Cleanups
//-----------------------------------------------------------------------------

#pragma region User

#pragma endregion // User

#endif // DJOEZEKE_RECAPTURE_H
