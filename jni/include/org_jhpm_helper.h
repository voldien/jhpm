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
#ifndef _ORG_JHPM_HELPER_H_
#define _ORG_JHPM_HELPER_H_ 1
#include <jni.h>
#include<assert.h>
#include <hpm/hpm.h>

/**
 *	Get object float pointer.
 *	@Return get float array data type.
 */
HPM_ALWAYS_INLINE jfloatArray hpmjni_get_float_array_reference(
        JNIEnv* __restrict__ env, jobject __restrict__ objref) {

	/*	Check if object reference is valid. */
	assert(objref);

	/*	Get class type from object.	*/
	jclass cs = (*env)->GetObjectClass(env, objref);
	jfieldID field = (*env)->GetFieldID(env, cs, "e", "[F");

	/*	Get float array reference object.	*/
	jfloatArray arr = (*env)->GetObjectField(env, objref, field);

	/*	return float array object.  */
	return arr;
}

/**
 *	Get object float pointer.
 *	@Return get float array pointer data.
 */
HPM_ALWAYS_INLINE jfloat* hpmjni_get_float_array_pointer_reference(
        JNIEnv* __restrict__ env, jobject __restrict__ objref,
        jfloatArray* __restrict__ array) {

	/*	Requires non null object and array pointer.	*/
	assert(objref && array);

	/*	Fetch float array object.	*/
	*array = hpmjni_get_float_array_reference(env, objref);

	/*	Get class type from object.	*/
	return (*env)->GetFloatArrayElements(env, *array, NULL);
}

/**
 *	Get object float pointer.
 *	@Return get float array pointer data.
 */
HPM_ALWAYS_INLINE void hpmjni_get_float_array_pointer_reference_a_b(
        JNIEnv* __restrict__ env, jobject* __restrict__ objref,
        jfloatArray** __restrict__ parray, jfloat** __restrict__ pfloat) {

	const int n = 2;
	int i;

	/*	Requires non null object and array pointer.	*/
	assert(objref && parray && pfloat);

	/*	Get float pointer for each float array objects. */
	for(i = 0; i < n; i++){
		pfloat[i] = hpmjni_get_float_array_pointer_reference(env, objref[i], parray[i]);
	}
}

/**
 *	Release
 */
HPM_ALWAYS_INLINE void hpmjni_release_float_array_pointer_reference(
        JNIEnv* __restrict__ env, const jfloatArray __restrict__ array,
        const jfloat* __restrict__ fp) {

	assert(array && fp);

	(*env)->ReleaseFloatArrayElements(env, array, fp, 0);
}

/**
 *	Get object float pointer.
 *	@Return get float array pointer data.
 */
HPM_ALWAYS_INLINE void hpmjni_get_float_array_pointer_reference_a_b_c(
        JNIEnv* __restrict__ env, jobject* __restrict__ objref,
        jfloatArray** __restrict__ parray, jfloat** __restrict__ pfloat) {

	const int n = 3;
	int i;

	/*	Requires non null object and array pointer.	*/
	assert(objref && parray && pfloat);

	/*	Get float pointer for each float array objects. */
	for(i = 0; i < n; i++){
		pfloat[i] = hpmjni_get_float_array_pointer_reference(env, objref[i], parray[i]);
	}
}

/**
 *	Get object float pointer.
 *	@Return get float array pointer data.
 */
HPM_ALWAYS_INLINE void hpmjni_release_float_array_pointer_reference_a_b(
        JNIEnv* __restrict__ env, jfloatArray** __restrict__ parray, jfloat** __restrict__ pfloat) {

	const int n = 2;
	int i;

	/*	Requires non null object and array pointer.	*/
	assert(parray && pfloat);

	/*	Release all float array objects.    */
	for(i = 0; i < n; i++){
		(*env)->ReleaseFloatArrayElements(env, parray[i], pfloat[i], 0);
	}
}

/**
 *	Release float pointer array.
 */
HPM_ALWAYS_INLINE void hpmjni_release_float_array_pointer_reference_a_b_c(
        JNIEnv* __restrict__ env, jfloatArray* __restrict__ parray,
        jfloat** __restrict__ pfloat) {

	const int n = 3;
	int i;

	/*	Requires non null object and array pointer.	*/
	assert(parray && pfloat);

	/*	Release each float array objects.    */
	for(i = 0; i < n; i++){
		(*env)->ReleaseFloatArrayElements(env, parray[i], pfloat[i], 0);
	}
}

/**
 *	Create instance object of
 *	specified class type.
 *
 *	@Return
 */
HPM_ALWAYS_INLINE jobject hpmjni_create_object_instance(
        JNIEnv* __restrict__ env, jclass __restrict__ c) {

	/*	Get constructor method ID.	*/
	jmethodID constructor = (*env)->GetMethodID(env, c, "<init>", "()V");

	/*	Create new object.	*/
	jobject o = (*env)->NewObject(env, c, constructor);

	/*	*/
	return o;
}

/**
 *	Create clone.
 *
 *	@Return clone object.
 */
HPM_ALWAYS_INLINE jobject hpmjni_create_clone(JNIEnv* __restrict__ env,
        jobject __restrict__ o) {
	jclass c = (*env)->GetObjectClass(env, o);

	jmethodID mid = (*env)->GetMethodID(env, c, "<init>", "()V");

	return (*env)->NewObject(env, c, mid, o);
}

#endif
