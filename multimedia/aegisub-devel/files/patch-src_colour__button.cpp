--- src/colour_button.cpp.orig	2020-06-01 05:02:40 UTC
+++ src/colour_button.cpp
@@ -18,6 +18,7 @@
 
 #include "dialogs.h"
 
+#include <boost/version.hpp>
 #if BOOST_VERSION >= 106900
 #include <boost/gil.hpp>
 #else
