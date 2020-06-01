--- src/video_frame.cpp.orig	2020-06-01 05:04:35 UTC
+++ src/video_frame.cpp
@@ -16,6 +16,7 @@
 
 #include "video_frame.h"
 
+#include <boost/version.hpp>
 #if BOOST_VERSION >= 106900
 #include <boost/gil.hpp>
 #else
