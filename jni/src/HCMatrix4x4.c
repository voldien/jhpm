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
#include"org_jhpm_helper.h"
#include<hpm/hpm.h>
#include<hpm/hpmmath.h>
#include<assert.h>

JNIEXPORT jboolean JNICALL Java_org_jhpm_Matrix4x4_isIdentity
  (JNIEnv * env, jobject o){
	const hpmvec4x4f_t id;

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Create identity for comparing.	*/
	hpm_mat4x4_identityfv((hpmvec4f*)id);

	/*	Performance compare.	*/
	jboolean status = hpm_mat4_eqfv((const hpmvec4f*)e, (const hpmvec4f*)id);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return status;
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Matrix4x4_determinant
  (JNIEnv * env, jobject o){

	/*	Get memory pointer of c object.	*/
	jfloatArray arr;
	jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	/*	Compute the determine of the matrix.	*/
	jfloat det = hpm_mat4x4_determinantfv((const hpmvec4f*)e);

	/*	Release float array.	*/
	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return det;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_inverse
  (JNIEnv * env, jobject o){

	/*	Create clone object.	*/
	jobject c = hpmjni_create_clone(env, o);

	/**/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloatArray arrinv = (*env)->GetFloatArrayElements(env, arr, NULL);
	float_t* e = (*env)->GetFloatArrayElements(env, arr, NULL);
	float_t* einv = (*env)->GetFloatArrayElements(env, arrinv, NULL);

	/*	*/
	hpm_mat4x4_inversefv(e, einv);

	/*	*/
	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);
	(*env)->ReleaseFloatArrayElements(env, arrinv, einv, 0);

	/*	*/
	return c;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_transpose
  (JNIEnv * env, jobject o){

	/*	Create clone object.	*/
	jfloatArray arr;
	jobject c = hpmjni_create_clone(env, o);
	/*	Get memory pointer of c object.	*/
	jfloat* e = hpmjni_get_float_array_pointer_reference(env, o, &arr);

	hpm_mat4x4_transposefv((hpmvec4f*)e);

	hpmjni_release_float_array_pointer_reference(env, arr, e);
	return c;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_get__I
  (JNIEnv *env, jobject o, jint i){

	jobject co = hpmjni_create_object_instance(env, NULL);

	return (*env)->ThrowNew(env, (*env)->FindClass(env, "java/lang/UnsupportedOperationException"), "Not implemented");
}

JNIEXPORT jfloat JNICALL Java_org_jhpm_Matrix4x4_get__II
  (JNIEnv *env, jobject o, jint i, jint j){

	/*	Get memory pointer of c object.	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);

	/*	*/
	jfloat* f = (jfloat*)(*env)->GetFloatArrayElements(env, arr, NULL);

	/*	*/
	jfloat val = f[i * 4 + j];

	/*	*/
	(*env)->ReleaseFloatArrayElements(env, arr, f, 0);
	return val;
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_add
  (JNIEnv *env, jobject o1, jobject o2){

	jobject objs[3] = {o1, o2, NULL};
	jfloatArray arry[3];
	jfloat* eo[3];

	/*	Create copy instance.	*/
	objs[2] = hpmjni_create_clone(env, o1);

	/*	*/
	hpmjni_get_float_array_pointer_reference_a_b_c(env, objs, arry, eo);

	/*	*/
	hpm_mat4x4_additition_mat4x4fv(eo[0], eo[1], eo[2]);

	/*	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arry, eo);

	return objs[2];
}

JNIEXPORT jobject JNICALL Java_org_jhpm_Matrix4x4_sub
  (JNIEnv *env, jobject o1, jobject o2){
	jobject objs[3] = {o1, o2, NULL};
	jfloatArray arry[3];
	jfloat* eo[3];

	/*	Create copy instance.	*/
	objs[2] = hpmjni_create_clone(env, o1);

	/*	*/
	hpmjni_get_float_array_pointer_reference_a_b_c(env, objs, arry, eo);

	/*	*/
	hpm_mat4x4_subraction_mat4x4fv(eo[0], eo[1], eo[2]);

	/*	*/
	hpmjni_release_float_array_pointer_reference_a_b_c(env, arry, eo);

	return objs[2];
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

	hpmboolean status = hpm_mat4_eqfv((hpmvec4f*)e1, (hpmvec4f*)e2);

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

	/*	*/
	jfloatArray arr = hpmjni_get_float_array_reference(env, o);
	jfloatArray arrquat = hpmjni_get_float_array_reference(env, o);
	float_t* e = (*env)->GetFloatArrayElements(env, arr, NULL);
	float_t* equat = (*env)->GetFloatArrayElements(env, arrquat, NULL);

	/*	*/
	hpm_mat4x4_rotationQf(e, equat);

	/*	*/
	(*env)->ReleaseFloatArrayElements(env, arr, e, 0);
	(*env)->ReleaseFloatArrayElements(env, arrquat, equat, 0);

	/*	*/
	return c;
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
