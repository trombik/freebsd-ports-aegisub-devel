--- src/video_provider_dummy.cpp.orig	2020-06-01 05:05:13 UTC
+++ src/video_provider_dummy.cpp
@@ -45,6 +45,7 @@
 #include <boost/algorithm/string/predicate.hpp>
 #include <boost/filesystem/path.hpp>
 #include <libaegisub/format.h>
+#include <boost/version.hpp>
 #if BOOST_VERSION >= 106900
 #include <boost/gil.hpp>
 #else
