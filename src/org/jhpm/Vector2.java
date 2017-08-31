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
package org.jhpm;

import java.util.Arrays;
import java.util.Objects;

/**
 * 
 * @author Valdemar Lindberg
 */
public class Vector2 {
	
	private float[] e;

	Vector2(){
		e = new float[2];
	}
	Vector2(float val){
		e = new float[2];
		set(val, val);
	}
	Vector2(float x, float y){
		e = new float[2];
		set(x, y);
	}

	/**
	 * 
	 * @return
	 */
	public native Vector2 negate();

	/**
	 * 
	 * @param index
	 * @return
	 */
	public native float get(int index);

	/**
	 * Compute length.
	 * @return
	 */
	public native float length();
	
	/**
	 * 
	 * @return
	 */
	public native float squaredLength();

	/**
	 * 
	 */
	public native void makeUnitVector();

	/**
	 * 
	 * @param x
	 */
	public native void setX(float x);
	
	/**
	 * 
	 * @param x
	 */
	public native void setY(float y);

	/**
	 *	@return
	 */
	public native float x();
	
	/**
	 * 
	 * @return
	 */
	public native float y();
	
	/**
	 * 
	 * @param x
	 * @param y
	 */
	public native void set(float x, float y);

	/**
	 *	@return
	 */
	public native float minComponent();
	public native float maxComponent();
	public native float maxAbsComponent();
	public native float minAbsComponent();
	public native int indexOfMinComponent();
	public native int indexOfMaxComponent();
	public native int indexOfMinAbsComponent();
	public native int indexOfMaxAbsComponent();

	/**
	 *	@return
	 */
	public native Vector2 normalize();

	/**
	 *	Compare vector equalities
	 *	.
	 *	@return
	 */
	@Override
	public native boolean equals(Object obj);
	
	/**
	 * 
	 */
	@Override
	public int hashCode() {
		return Objects.hash(Arrays.hashCode(e));
	}

	/**
	 *
	 *	@return
	 */
	@Override
	public native String toString();

	/**
	 * 
	 * @param v1
	 * @return
	 */
	public native Vector2 add(final Vector2 v1);

	/**
	 * 
	 * @param v1
	 * @return
	 */
	public native Vector2 sub(final Vector2 v1);

	/**
	 * 
	 * @param v1
	 * @return
	 */
	public native Vector2 div(final Vector2 v1);

	/**
	 * 
	 * @param f1
	 * @return
	 */
	public native Vector2 div(final float f1);

	/**
	 * 
	 * @param f1
	 * @return
	 */
	public native Vector2 mul(final Vector2 f1);

	/**
	 * 
	 * @param f1
	 * @return
	 */
	public native Vector2 mul(final float f1);

	/**
	 * 
	 */
	@Override
	protected native Object clone();

	/**
	 * 
	 * @param v
	 * @return
	 */
	public static native Vector2 unitVector3(final Vector2 v);

	/**
	 * 
	 * @param v1
	 * @param v2
	 * @return
	 */
	public static native Vector2 minVec(final Vector2 v1, final Vector2 v2);

	/**
	 * 
	 * @param v1
	 * @param v2
	 * @return
	 */
	public static native Vector2 maxVec(final Vector2 v1, final Vector2 v2);

	/**
	 * 
	 * @param vector
	 * @param normal
	 * @return
	 */
	public static native Vector2 reflection(final Vector2 vector, Vector2 normal);

	/**
	 * 
	 * @param v1
	 * @param v2
	 * @return
	 */
	public static native float dot(final Vector2 v1, final Vector2 v2);

	/**
	 * 
	 * @return
	 */
	public native static Vector2 zero();
}
