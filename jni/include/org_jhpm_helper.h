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
HPM_ALWAYS_INLINE jfloatArray hpmjni_get_float_array_reference(JNIEnv * env, jobject objref){

	/*	Get class type from object.	*/
	jclass cs = (*env)->GetObjectClass(env, objref);
	jfieldID field = (*env)->GetFieldID(env, cs, "e", "[F");

	/*	Get float array reference object.	*/
	jfloatArray arr = (*env)->GetObjectField(env, objref, field);

	/*	*/
	return arr;
}

/**
 *	Get object float pointer.
 *	@Return get float array data type.
 */
HPM_ALWAYS_INLINE jfloat* hpmjni_get_float_array_pointer_reference(JNIEnv * env, jobject objref, jfloatArray* array){

	/**/
	assert(objref && array);

	/*	*/
	*array = hpmjni_get_float_array_reference(env, objref);

	/*	Get class type from object.	*/
	return (*env)->GetFloatArrayElements(env, *array, NULL);
}

/**
 *	Create instance object of
 *	specified class type.
 *
 *	@Return
 */
HPM_ALWAYS_INLINE jobject hpmjni_create_object_instance(JNIEnv* env, jclass c){

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
HPM_ALWAYS_INLINE jobject hpmjni_create_clone(JNIEnv* env, jobject o){
	jclass c = (*env)->GetObjectClass(env, o);

	jmethodID mid = (*env)->GetMethodID(env, c, "<init>", "()V");

	return (*env)->NewObject(env, c, mid, o);
}

#endif
