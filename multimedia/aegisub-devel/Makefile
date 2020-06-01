# Created by: Leinier Cruz Salfran <salfrancl@yahoo.es>
# $FreeBSD: head/multimedia/aegisub/Makefile 528343 2020-03-13 09:47:16Z jbeich $

PORTNAME=	aegisub-devel
DISTVERSION=    g20200601
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Cross-platform subtitle editor

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

NOT_FOR_ARCHS=		powerpc64
NOT_FOR_ARCHS_REASON_powerpc64=		No support for PowerPC 64 bit mode

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libicui18n.so:devel/icu \
		libass.so:multimedia/libass \
		libfontconfig.so:x11-fonts/fontconfig

BROKEN_aarch64=		Fails to compile: no support for this architecture (yet)
USES=		compiler:c++11-lib desktop-file-utils gettext gl gmake gnome \
		iconv localbase pkgconfig tar:xz autoreconf lua:51
USE_GITHUB= yes
GH_ACCOUNT= Aegisub
GH_PROJECT= Aegisub
GH_TAGNAME= 85f711f
USE_GNOME=	intltool
USE_WX=		3.0
WX_CONF_ARGS=	absolute
USE_GL=		gl
USE_CSTD=	c99
USE_CXXSTD=	c++11
CPPFLAGS+=	-DU_USING_ICU_NAMESPACE=1
LDFLAGS+=	-Wl,--as-needed # freetype
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ICONV_LIBS="${ICONV_LIB}" PTHREAD_LIBS="-pthread" \
		agi_cv_with_iconv=yes
CONFIGURE_ARGS=	--disable-compiler-flags \
		--disable-gcc-prec \
		--disable-sanity-checks \
		--disable-update-checker \
		--without-libc++ \
		--with-boost-libdir=${PREFIX}/lib \
		${ICONV_CONFIGURE_ARG}
INSTALLS_ICONS=	yes

PLIST_SUB=	VERSION="${PORTVERSION:R}"

OPTIONS_DEFINE=		ALSA DOCS FFMPEG FFTW HUNSPELL OPENAL PORTAUDIO \
			PULSEAUDIO
OPTIONS_DEFAULT=	FFMPEG FFTW HUNSPELL PULSEAUDIO

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_OFF=	--without-alsa
FFMPEG_LIB_DEPENDS=	libffms2.so:multimedia/ffms2
FFMPEG_CONFIGURE_OFF=	--without-ffms
FFTW_LIB_DEPENDS=	libfftw3.so:math/fftw3
FFTW_CONFIGURE_OFF=	--without-fftw3
HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
HUNSPELL_CONFIGURE_OFF=	--without-hunspell
OPENAL_USES=		openal
OPENAL_CONFIGURE_OFF=	--without-openal
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_CONFIGURE_OFF=\
			--without-portaudio
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_OFF=\
			--without-libpulse

# src/audio_display.o: undefined reference to symbol '__atomic_load_8@@LIBATOMIC_1.0'
.if empty(CFLAGS:M-march=*)
CFLAGS+=		${CFLAGS_${ARCH}_${CHOSEN_COMPILER_TYPE}}
CFLAGS_i386_gcc=	-march=pentium
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|".*build/|"./build/|' ${WRKSRC}/build/version.sh
	@${REINPLACE_CMD} -e \
		's|^CC=|CC?=| ; \
		 /^CCOPT_/s|=.*|=| ; \
		 /^CCDEBUG/s|=.*|=|' ${WRKSRC}/vendor/luajit/src/Makefile
# expr 6962 + `git log --pretty=oneline 16cd907fe7482cb54a7374cd28b8501f138116be..HEAD | wc -l`
AEGISUB_GITHUB_REVISION=	9010

pre-configure:
	echo "#define BUILD_GIT_VERSION_NUMBER ${AEGISUB_GITHUB_REVISION}" > ${WRKSRC}/build/git_version.h
	echo "#define BUILD_GIT_VERSION_STRING \"${GH_TAGNAME}\"" >> ${WRKSRC}/build/git_version.h
	echo "#define TAGGED_RELEASE 0" >> ${WRKSRC}/build/git_version.h
	echo "#define INSTALLER_VERSION \"${GH_TAGNAME}\"" >> ${WRKSRC}/build/git_version.h
	echo "#define RESOURCE_BASE_VERSION \"\"" >> ${WRKSRC}/build/git_version.h

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		automation/v4-docs ${STAGEDIR}${DOCSDIR})
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/aegisub

.include <bsd.port.mk>
