/**
    High performance matrix library wrapper, utilizing SIMD extensions.
    Copyright (C) 2017  Valdemar Lindberg

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#include"org_jhpm_Quaternion.h"
#include<hpm/hpm.h>


JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_getPitch
  (JNIEnv *env, jobject o){
	jfloat pitch;

	/*	Get memory pointer of c object.	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, arr, NULL);

	pitch = hpm_quat_pitchfv(e);

	/*	Release float array.	*/
	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return pitch;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_getYaw
  (JNIEnv *env, jobject o){
	jfloat yaw;

	/*	Get memory pointer of c object.	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, arr, NULL);

	yaw = hpm_quat_yawfv(e);

	/*	Release float array.	*/
	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return yaw;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_getRoll
  (JNIEnv *env, jobject o){
	jfloat roll;

	/*	Get memory pointer of c object.	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, arr, NULL);

	roll = hpm_quat_rollfv(e);

	/*	Release float array.	*/
	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return roll;
}
JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_lookRotation
  (JNIEnv *env, jclass c, jobject o1, jobject o2){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_lookAt
  (JNIEnv *env, jclass c, jobject o1, jobject o2){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_createQuaternionOfAxis__FFF
  (JNIEnv *env, jclass c, jfloat x, jfloat y, jfloat z){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_createQuaternionOfAxis__Lorg_jhpm_Vector3_2
  (JNIEnv *env, jclass c, jobject o){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_createFromAxisAngle
  (JNIEnv *env, jclass c, jobject o1, jfloat f){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_createQuaternionOfDirection
  (JNIEnv *env, jclass c, jobject o1){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_lerp
  (JNIEnv *env, jclass c, jobject o1, jobject o2, jfloat t){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_slerp
  (JNIEnv *env, jclass c, jobject o1, jobject o2, jfloat t){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_identity
  (JNIEnv *env, jclass c){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}
