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

	/*	Compute quaternion pitch angle in radius.	*/
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

	/*	Compute quaternion yaw angle radius.	*/
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

	/*	Compute quaternion roll angle in radiuscd co.	*/
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
	jobject o;

	/*	Get memory pointer of c object.	*/
	o = hpmjni_create_object_instance(env, c);

	jfloatArray arro = hpmjni_get_float_array_reference(env, o);
	jfloatArray arr1 = hpmjni_get_float_array_reference(env, o1);
	jfloatArray arr2 = hpmjni_get_float_array_reference(env, o2);

	jfloat* eo = (*env)->GetFloatArrayElements(env, arro, NULL);
	jfloat* e1 = (*env)->GetFloatArrayElements(env, arr1, NULL);
	jfloat* e2 = (*env)->GetFloatArrayElements(env, arr2, NULL);

	/*	Compute the lerp.	*/
	hpm_quat_lerpfv(e1, e2, t, eo);

	/*	Release float array.	*/
	(*env)->ReleaseFloatArrayElements(env, arro, eo, 0);
	(*env)->ReleaseFloatArrayElements(env, arr1, e1, 0);
	(*env)->ReleaseFloatArrayElements(env, arr2, e2, 0);

	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_slerp
  (JNIEnv *env, jclass c, jobject o1, jobject o2, jfloat t){
	jobject o;

	/*	Get memory pointer of c object.	*/
	o = hpmjni_create_object_instance(env, c);

	jfloatArray arro = hpmjni_get_float_array_reference(env, o);
	jfloatArray arr1 = hpmjni_get_float_array_reference(env, o1);
	jfloatArray arr2 = hpmjni_get_float_array_reference(env, o2);

	jfloat* eo = (*env)->GetFloatArrayElements(env, arro, NULL);
	jfloat* e1 = (*env)->GetFloatArrayElements(env, arr1, NULL);
	jfloat* e2 = (*env)->GetFloatArrayElements(env, arr2, NULL);

	/*	Compute the slerp.	*/
	hpm_quat_slerpfv(e1, e2, t, eo);

	/*	Release float array.	*/
	(*env)->ReleaseFloatArrayElements(env, arro, eo, 0);
	(*env)->ReleaseFloatArrayElements(env, arr1, e1, 0);
	(*env)->ReleaseFloatArrayElements(env, arr2, e2, 0);

	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_identity
  (JNIEnv *env, jclass c){
	jobject o;

	/*	Get memory pointer of c object.	*/
	o = hpmjni_create_object_instance(env, c);

	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, arr, NULL);

	hpm_quat_identityfv(e);

	/*	Release float array.	*/
	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return o;
}
