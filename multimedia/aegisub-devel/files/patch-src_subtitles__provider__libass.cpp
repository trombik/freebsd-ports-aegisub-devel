--- src/subtitles_provider_libass.cpp.orig	2020-06-01 05:03:36 UTC
+++ src/subtitles_provider_libass.cpp
@@ -46,6 +46,7 @@
 #include <libaegisub/util.h>
 
 #include <atomic>
+#include <boost/version.hpp>
 #if BOOST_VERSION >= 106900
 #include <boost/gil.hpp>
 #else
