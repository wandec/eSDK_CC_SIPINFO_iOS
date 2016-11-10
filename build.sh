#!/bin/bash
TARGET="eSpaceCCSDK"

echo "---- ${TARGET} build start -----"

#当前版本是C50的,所以按照缩写,写成V1.5.50
eSpaceCCVERSION=V1.5.50
DEMO_VERSION=V100R005C50
PRODUCT_NAME="eSDK_eSpace_CC_API_${eSpaceCCVERSION}_IOS.zip"

SDKVERSION=`xcrun -sdk iphoneos --show-sdk-version`
SDKPARAM="iphoneos${SDKVERSION}"
ARMPARAM="armv7"
ARMPARAM1="arm64"

#other vars
cd ./
BASE_DIR=$PWD
echo "using BASE_DIR ${BASE_DIR}"

#按照日期生成不同的输出目录
CURRENT_DATE=`date +%Y-%m-%d`
PACKAGE_DIR="${BASE_DIR}/build/${CURRENT_DATE}"

#定位开源库的目录
#PLATFORM_DIR="${BASE_DIR}/src/eSDK_eSpace_CC_API/Depend/Private/"
OPEN_SRC_DIR="${BASE_DIR}/third-party/"

#资源文件路径
SOURCE_DIR="${BASE_DIR}/src/eSDK_eSpace_CC_API"
BUILD_DIR="${SOURCE_DIR}/Build"
DEPEND_DIR="${SOURCE_DIR}/Depend"

#PRIVATE_DEPEND_DIR="${DEPEND_DIR}/Private"
PUBLIC_DEPEND_DIR="${DEPEND_DIR}/Public"

# 先创建当天的输出目录
mkdir -p ${PACKAGE_DIR}


# 切到输出目录后,检查有没有之前生成的demo压缩包或者导出目录,有的话,就先删除了
cd ${PACKAGE_DIR}

if [ $? -ne 0 ]; then
	#statements
	echo "change to demo output dir fail, please check it"
	exit -3
fi
rm -rf *

echo "change to eSpaceCC ios sdk source dir"
set -e
cd ${SOURCE_DIR}

if [ -d ${BUILD_DIR} ]; then
	#statements
	echo "---- build dir exist, it should be removed later ----"
	rm -rf ${BUILD_DIR}
fi

if [ -d ${DEPEND_DIR} ]; then
	#statements
	cd ${DEPEND_DIR}/Public
	rm -rf *
	cd ${SOURCE_DIR}
fi

echo "copy private depend lib"
#mkdir -p ${PRIVATE_DEPEND_DIR}
#cp -R ${PLATFORM_DIR} ${PRIVATE_DEPEND_DIR}
#cp -R ${SELF_DEV_DIR} ${PRIVATE_DEPEND_DIR}

mkdir -p ${PUBLIC_DEPEND_DIR}
echo "copy opensrc depend lib"
cp -R ${OPEN_SRC_DIR} ${PUBLIC_DEPEND_DIR}

#rm -rf bin include lib src
cd ${SOURCE_DIR}

Y_ARMV7_BUILD_PATH="${PACKAGE_DIR}/temp/armv7"

echo "lipo armv7 and arm64 "

#如果目标文件不存在则创建
if [ ! -d "${Y_ARMV7_BUILD_PATH}" ]; then
  mkdir -p "${Y_ARMV7_BUILD_PATH}"
fi 
MY_CURRENT_BUILD_PATH="${Y_ARMV7_BUILD_PATH}"
xcodebuild -target ${TARGET} -configuration "Release" CONFIGURATION_BUILD_DIR="${MY_CURRENT_BUILD_PATH}" -arch ${ARMPARAM} -sdk "${SDKPARAM}" 

Y_ARM64_BUILD_PATH="${PACKAGE_DIR}/temp/arm64"
#如果目标文件不存在则创建
if [ ! -d "${Y_ARM64_BUILD_PATH}" ]; then
  mkdir -p "${Y_ARM64_BUILD_PATH}"
fi 
MY_CURRENT_BUILD_PATH="${Y_ARM64_BUILD_PATH}"
xcodebuild -target ${TARGET} -configuration "Release" -arch ${ARMPARAM1} -sdk "${SDKPARAM}" CONFIGURATION_BUILD_DIR="${MY_CURRENT_BUILD_PATH}"

#check if device lib compiling ok
if [ $? -ne 0 ]; then
	#statements
	echo "build device lib fail, compiling will stop."
	exit -2;
fi

cd ${SOURCE_DIR}
echo "start to lipo the final framework"
# TARGET 名字
MY_TARGET_NAME="eSpaceCCSDK"

#LIB名字
MY_STATIC_LIB="lib${MY_TARGET_NAME}.a"

#最终静态库路径
MY_FINAL_BUILD_PATH="${PACKAGE_DIR}"

#最终静态库名字
MY_FINAL_STATIC_LIB="${MY_STATIC_LIB}"

xcodebuild -target ${TARGET} -configuration "Release" -arch ${ARMPARAM1} -sdk "${SDKPARAM}" CONFIGURATION_BUILD_DIR="${MY_FINAL_BUILD_PATH}"

if [ ! -d "${MY_FINAL_BUILD_PATH}" ]; then
  mkdir -p "${MY_FINAL_BUILD_PATH}"
  
fi

lipo -create "${Y_ARMV7_BUILD_PATH}/${MY_STATIC_LIB}" "${Y_ARM64_BUILD_PATH}/${MY_STATIC_LIB}" -output "${MY_FINAL_BUILD_PATH}/${MY_FINAL_STATIC_LIB}"

cp -R ${SOURCE_DIR}/eSpaceCCSDK/VTMCommonDefine.h ${PACKAGE_DIR}/include/eSpaceCCSDK
cp -R ${SOURCE_DIR}/eSpaceCCSDK/VTMNotificationsDefine.h ${PACKAGE_DIR}/include/eSpaceCCSDK

if [ -d ${BUILD_DIR} ]; then
	#statements
	echo "---- demo build dir exist, it should be removed later ----"
	rm -rf ${BUILD_DIR}
fi

if [ $? -ne 0 ]; then
	#statements
	echo "copy Error!!!!!!!"
	exit -3
fi
echo "copy success !!!!!!!!!"
echo "*************************** build eSpaceCC SDK lib success *****************************"

echo "*************************** start to Build eSpaceCC SDK Demo *****************************"

cd ${BASE_DIR}

DEMO_DIR="${BASE_DIR}/sample/eSDKCC(iPhone)"

echo "*************************** start to Build Demo ${DEMO_DIR} **************************"

DEMO_BUILD_DIR="${DEMO_DIR}/Build"
DEMO_DEPEND_DIR="${DEMO_DIR}/Depend"
DEMO_PRODUCT_NAME="eSDK_eSpace_CC_API_${DEMO_VERSION}_IOS_Demo.zip"


#INSTALLIDENTITY="iPhone Distribution: shuming gao (QDD3W348GG)"

SCHEME="eSpaceCCDemo"
ARCHIVE="eSpaceCCDemo"
#IPANAME="eSpaceCCDemo"
EXPORT_FOLDER_NAME="eSpaceCCDemo"


if [ -d ${DEMO_BUILD_DIR} ]; then
	#statements
	echo "---- demo build dir exist, it should be removed later ----"
	rm -rf ${DEMO_BUILD_DIR}
fi

if [ -d ${DEMO_DEPEND_DIR} ]; then
	#statements
	cd ${DEMO_DEPEND_DIR}
	rm -rf *
	cd ${DEMO_DIR}
fi

echo "*************************** Start ${SCHEME} Build *****************************"

mkdir ${DEMO_BUILD_DIR}

echo "copy demo depend lib"
cp -R ${PACKAGE_DIR}/libeSpaceCCSDK.a ${DEMO_DEPEND_DIR}
cp -R ${PACKAGE_DIR}/include ${DEMO_DEPEND_DIR}
cp -R ${SOURCE_DIR}/Depend/Private/AnyOffice/SvnSdk.framework ${DEMO_DEPEND_DIR}
cp -R ${OPEN_SRC_DIR}/openssl/openssl.framework ${DEMO_DEPEND_DIR}

touch ${DEMO_BUILD_DIR}/log.txt

#清理工作,将之前导出到输出目录中的demo目录删除了
if [ -e ${BASE_DIR}/build ]; then
	#statements
	echo "---- clean demo ----"
	rm -rf ${BASE_DIR}/build
	rm -rf ${DEMO_BUILD_DIR}

else
	echo "---- clean demo fail ----"
	exit -6
fi

echo "---- now we can get demo success ----"
