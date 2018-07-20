CMAKE_MINIMUM_REQUIRED(VERSION 3.4.2)
PROJECT(javahpm)

# jhpm version setup.
SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 1)
SET(VERSION_REVISION 0)
SET(VERSION_STATE b)
SET(VERSION ${VERSION_MAJOR}.${VERSION_MINOR}${VERSION_STATE}${VERSION_REVISION} )

# Set version preprocessor macros.
MESSAGE(STATUS "Version ${VERSION}")
ADD_DEFINITIONS(-DHPM_MAJOR_VERSION=${HPM_VERSION_MAJOR})
ADD_DEFINITIONS(-DHPM_MINOR_VERSION=${HPM_VERSION_MINOR})
ADD_DEFINITIONS(-DHPM_REVISION_VERSION=${HPM_VERSION_REVISION})
ADD_DEFINITIONS(-DHPM_STATE_VERSION=${HPM_VERSION_STATE})
ADD_DEFINITIONS(-DHPM_STR_VERSION="${HPM_VERSION}")

# Check build target.
IF (CMAKE_BUILD_TYPE STREQUAL "Release")
	MESSAGE(STATUS "Compile for release.")
	ADD_DEFINITIONS(-DNDEBUG -O2)
	SET(CMAKE_RELEASE TRUE)
ELSEIF( CMAKE_BUILD_TYPE STREQUAL "Debug")
	MESSAGE(STATUS "Compile for debug.")
	ADD_DEFINITIONS(-D_DEBUG)
	ADD_DEFINITIONS(-g3)
	SET(CMAKE_DEBUG TRUE)
ENDIF()

# Check if package exist in order to continue.
FIND_PACKAGE(JNI REQUIRED)
FIND_PACKAGE(Java REQUIRED)

# Needs UseJava module in order to work.
INCLUDE(UseJava)
INCLUDE_DIRECTORIES(${JNI_INCLUDE_DIRS})

# Set java compiler options.
SET(CMAKE_JAVA_COMPILE_FLAGS "-source" "1.6" "-target" "1.6")
SET(CMAKE_JNI_TARGET TRUE)
SET(JAVA_SOURCE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/org/jhpm)
SET(PACKAGE_NAME "org.jhpm")
SET(CMAKE_JAR_CLASSES_PREFIX org/jhpm)

# Java source code.
FILE (GLOB JAVA_SOURCE_FILES ${JAVA_SOURCE_DIRECTORY}/*.java)

# Set Java target
add_jar(jhpm ${JAVA_SOURCE_FILES}
	OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib
	VERSION 1.6)

# Get property of the jhpm.
get_target_property(_jarFile jhpm JAR_FILE)
get_target_property(_classDir jhpm CLASSDIR)

# Print properties.
MESSAGE(STATUS "Jar file ${_jarFile}")
MESSAGE(STATUS "Class compiled to ${_classDir}")

# Generate C/C++ header only if the target java library exists.
IF(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/lib/jhpm.jar )
	SET(JAVA_SOURCE_CLASSSES org.jhpm.Vector2 org.jhpm.Vector3 org.jhpm.Vector4 org.jhpm.Quaternion
				org.jhpm.Matrix4x4 org.jhpm.Hpm )

	MESSAGE(STATUS "Generating JNI C/C++ Headers.")
	create_javah(GENERATED_FILES files_headers
		CLASSES ${JAVA_SOURCE_CLASSSES}
		CLASSPATH ${_jarFile}
		OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/jni/include)
	# JNI.
	ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/jni)
ENDIF()

# Temporarily solution!
IF( NOT JAVA_LIB_INSTALL_DIR)
	IF( UNIX)
		SET(JAVA_LIB_INSTALL_DIR /usr/share/java)
	ENDIF()
ENDIF()

#install_jar(target_name destination)
install_jar(jhpm DESTINATION ${LIB_INSTALL_DIR}/jhpm)
install_jni_symlink(jhpm DESTINATION ${JAVA_LIB_INSTALL_DIR})

# Create html documenation for the Java API for this library.
IF( DOCS )
	create_javadoc(docs
	   PACKAGES org.jhpm
	   FILES ${JAVA_SOURCE_FILES}
	   CLASSPATH ${CMAKE_JAVA_INCLUDE_PATH}
	   WINDOWTITLE "Source"
	   DOCTITLE "<h1>jhpm API documentation</h1>"
	   AUTHOR FALSE
	   USE TRUE
	   VERSION TRUE
	)
ENDIF()

# Distribution target.
IF( UNIX )
	SET( TARGETDIR "${PROJECT_NAME}-${VERSION}")
	ADD_CUSTOM_TARGET(	distribution
				COMMAND mkdir -p ${TARGETDIR}
				COMMAND cp -r src jni CMakeLists.txt LICENSE ${TARGETDIR}
				COMMAND tar cf - ${TARGETDIR} | gzip -c > ${TARGETDIR}.tar.gz
				COMMAND rm -r ${TARGETDIR} )
ENDIF()

