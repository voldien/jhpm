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
#include"org_jhpm_Matrix4x4.h"
#include<hpm/hpm.h>
#include<hpm/hpmmath.h>
#include<assert.h>

JNIEXPORT jboolean JNICALL Java_org_jhpm_Matrix4x4_isIdentity
  (JNIEnv * env, jobject o){
	const hpmvec4x4f_t id;

	/*	Get memory pointer of c object.	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, arr, NULL);

	/*	Create identity for comparing.	*/
	hpm_mat4x4_identityfv(id);

	/*	Performance compare.	*/
	jboolean status = hpm_mat4_eqfv(e, id);

	/*	Release float array.	*/
	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return status;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Matrix4x4_determinant
  (JNIEnv * env, jobject o){

	/*	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, arr, NULL);

	/*	*/
	jfloat det = hpm_mat4x4_determinantfv(e);

	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return det;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_inverse
  (JNIEnv * env, jobject o){
	jobject c = hpmjni_create_clone(env, o);

	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	float_t* e = (*env)->GetFloatArrayElements(env, arr, NULL);

	hpm_mat4x4_inversefv(NULL, env);

	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);
	return c;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_transpose
  (JNIEnv * env, jobject o){
	return (*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_get__I
  (JNIEnv *env, jobject o, jint i){
	return (*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Matrix4x4_get__II
  (JNIEnv *env, jobject o, jint i, jint j){

	jfloatArray arr = hpmjni_get_float_array_reference(env, o);

	jfloat* f = (jfloat*)(*env)->GetFloatArrayElements(env, arr, NULL);

	jfloat val = f[i * 4 + j];

	(*env)->ReleaseFloatArrayElements(env, arr, f, 0);
	return val;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_add
  (JNIEnv *env, jobject o1, jobject o2){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_sub
  (JNIEnv *env, jobject o1, jobject o2){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_mul__Lorg_jhpm_Matrix4x4_2
  (JNIEnv *env, jobject o1, jobject o2){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_mul__F
  (JNIEnv *env, jobject o1, jfloat f){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_mul__Lorg_jhpm_Vector4_2
  (JNIEnv *env, jobject o1, jobject o2){
	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_clone(env, o1);

	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_clone
  (JNIEnv *env, jobject o){
	jobject clone = (*env)->AllocObject(env, (*env)->GetObjectClass(env, o));
	//env->SetFloatArrayRegion()
	return clone;
}

JNIEXPORT jboolean JNICALL Java_org_jhpm_Matrix4x4_equals
  (JNIEnv *env, jobject o1, jobject o2){

	jfloatArray arr1 = hpmjni_get_float_array_reference(env, o1);
	jfloatArray arr2 = hpmjni_get_float_array_reference(env, o2);

	jfloat* e1 = (jfloat*)(*env)->GetFloatArrayElements(env, arr1, NULL);
	jfloat* e2 = (jfloat*)(*env)->GetFloatArrayElements(env, arr2, NULL);

	hpmboolean status = hpm_mat4_eqfv(e1, e2);

	(*env)->ReleaseFloatArrayElements(env, arr1, e1, 0);
	(*env)->ReleaseFloatArrayElements(env, arr2, e2, 0);

	return status;
}

JNIEXPORT jstring JNICALL Java_org_jhpm_Matrix4x4_toString
  (JNIEnv *env, jobject o){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_translate__FFF
  (JNIEnv * env, jclass c, jfloat x, jfloat y, jfloat z){

	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);

	return (*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_translate__Lhpmjni_Vector3_2
  (JNIEnv * env, jclass c, jobject v1){

	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);

	return (*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_rotate__FLhpmjni_Vector3_2
  (JNIEnv *env, jclass c, jfloat r, jobject v1){

	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);

	return (*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_rotate__Lhpmjni_Quaternion_2
  (JNIEnv * env, jclass c, jobject q){

	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);

	return (*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_scale__FFF
  (JNIEnv *env, jclass c, jfloat x, jfloat y, jfloat z){

	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);

	/*	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, (jbyteArray)arr, NULL);

	hpm_mat4x4_scalef(e, x, y, z);

	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_scale__Lhpmjni_Vector3_2
  (JNIEnv *env, jclass c, jobject v1){

	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);

	/*	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, (jbyteArray)arr, NULL);


	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_perspective
  (JNIEnv *env, jclass c, jfloat angle, jfloat ratio, jfloat near, jfloat far){

	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);

	/*	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, (jbyteArray)arr, NULL);

	hpm_mat4x4_projfv(e, angle, ratio, near, far);

	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_lookAt
  (JNIEnv *env, jclass c, jobject o1, jobject o2, jobject o3){

	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);

	return (*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_orth
  (JNIEnv *env, jclass c, jfloat l, jfloat r, jfloat t, jfloat b, jfloat front, jfloat back){
	/*	Create default instance of the object.	*/
	jobject o = hpmjni_create_object_instance(env, c);

	/*	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, (jbyteArray)arr, NULL);

	hpm_mat4x4_orthfv(e, l, r, t, b, front, back);

	/*	*/
	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return o;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_biasMatrix
  (JNIEnv *env, jclass c){
	(*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_identity
  (JNIEnv *env, jclass c){

	/*	*/
	jobject o = hpmjni_create_object_instance(env, c);

	/*	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloat* e = (*env)->GetFloatArrayElements(env, (jbyteArray)arr, NULL);

	/*  */
	hpm_mat4x4_identityfv(e);

	/*  */
	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);

	return o;
}
