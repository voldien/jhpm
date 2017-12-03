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
#include"org_jhpm_helper.h"
#include<hpm/hpm.h>

JNIEXPORT void JNICALL Java_org_jhpm_Quaternion_set
  (JNIEnv *env, jobject o, jfloat w, jfloat x, jfloat y, jfloat z){

	jfloatArray arr;
	/*	Get memory pointer of c object.	*/
	jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	hpm_quat_setf((hpmquatf*)e, w, x, y, z);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_magnitude
  (JNIEnv* env, jobject o){
	jfloatArray arr;
	/*	Get memory pointer of c object.	*/
	jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	jfloat length = hpm_quat_lengthfv((const hpmquatf*)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return length;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_magnitudeSquared
  (JNIEnv* env, jobject o){
	jfloatArray arr;
	/*	Get memory pointer of c object.	*/
	jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	jfloat length = hpm_quat_lengthsqurefv((const hpmquatf*)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return length;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_dot
  (JNIEnv* env, jobject o1, jobject q1, jobject q2){
	jfloat innerproduct;

	jobject o[2] = {q1, q2};
	jfloatArray fa[2];
	jfloat* p[2];

	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	/*	Compute dot product.	*/
	innerproduct = hpm_quat_dotfv((const hpmvec4f*)p[0], (const hpmvec4f*)p[1]);

	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return innerproduct;
}

JNIEXPORT void JNICALL Java_org_jhpm_Quaternion_makeUnitQuaternion
  (JNIEnv* env, jobject o){
    jfloatArray arr;
    /*  */
    jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

    /*  */
    hpm_vec4_normalizefv((hpmvec4f*)e);

    /*  */
    hpmjni_release_float_array_pointer_reference(env, arr, e);
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_normalize
  (JNIEnv* env, jobject o){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_conjugate
  (JNIEnv* env, jobject o){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_inverse
  (JNIEnv* env, jobject o){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_clone
  (JNIEnv* env, jobject o1){



}

JNIEXPORT jboolean JNICALL Java_org_jhpm_Quaternion_equals
  (JNIEnv* env, jobject o1, jobject o2){

	jobject o[2] = {o1, o2};
	jfloatArray fa[2];
	jfloat* p[2];

	hpmjni_get_float_array_pointer_reference_a_b(env, o, fa, p);

	jboolean status = hpm_vec4_eqfv((const hpmvec4f*)p[0], (const hpmvec4f*)p[1]);

	hpmjni_release_float_array_pointer_reference_a_b(env, fa, p);
	return status;
}

JNIEXPORT jstring JNICALL Java_org_jhpm_Quaternion_toString
  (JNIEnv* env, jobject o ){
    jfloatArray arr;
    jchar text[128];
    jsize slen;

    /*  */
    jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

    /*	*/
    slen = sprintf((char*)text, "{ %.1f, %.1f, %.1f, %.1f }", e[0], e[1], e[2], e[3]);

    /*	*/
    hpmjni_release_float_array_pointer_reference(env, arr, e);
    return (*env)->NewString(env, text, slen);
}


JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_getPitch
  (JNIEnv *env, jobject o){
	jfloat pitch;

	jfloatArray arr;

	/*	Get memory pointer of c object.	*/
	jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute quaternion pitch angle in radius.	*/
	pitch = hpm_quat_pitchfv((const hpmquatf*)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);

	return pitch;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_getYaw
  (JNIEnv *env, jobject o){
	jfloat yaw;

	jfloatArray arr;

	/*	Get memory pointer of c object.	*/
	jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute quaternion yaw angle radius.	*/
	yaw = hpm_quat_yawfv((const hpmquatf*)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);

	return yaw;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Quaternion_getRoll
  (JNIEnv *env, jobject o){
	jfloat roll;

	jfloatArray arr;

	/*	Get memory pointer of c object.	*/
	jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute quaternion roll angle in radiuscd co.	*/
	roll = hpm_quat_rollfv((const hpmquatf*)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);

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

	/*	*/
	jfloatArray arro = hpmjni_get_float_array_reference(env, o);
	jfloatArray arr1 = hpmjni_get_float_array_reference(env, o1);
	jfloatArray arr2 = hpmjni_get_float_array_reference(env, o2);

	/*	*/
	jfloat* eo = (*env)->GetFloatArrayElements(env, arro, NULL);
	jfloat* e1 = (*env)->GetFloatArrayElements(env, arr1, NULL);
	jfloat* e2 = (*env)->GetFloatArrayElements(env, arr2, NULL);

	/*	Compute the slerp.	*/
	hpm_quat_slerpfv((const hpmquatf*)e1, (const hpmquatf*)e2, t, (hpmquatf*)eo);

	/*	Release float array.	*/
	(*env)->ReleaseFloatArrayElements(env, arro, eo, 0);
	(*env)->ReleaseFloatArrayElements(env, arr1, e1, 0);
	(*env)->ReleaseFloatArrayElements(env, arr2, e2, 0);

	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Quaternion_identity
  (JNIEnv *env, jclass c){
	jobject o;
	jfloatArray arr;

	/*	Get memory pointer of c object.	*/
	o = hpmjni_create_object_instance(env, c);

	/*	Get memory pointer of c object.	*/
	jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Create identitiy.	*/
	hpm_quat_identityfv((hpmquatf*)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);

	return o;
}
