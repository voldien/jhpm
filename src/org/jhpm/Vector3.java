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
public class Vector3 {

	private float[] e;

	Vector3() {
		e = new float[3];
	}

	Vector3(float val) {
		e = new float[3];
		setX(val);
		setY(val);
		setZ(val);
	}

	Vector3(float e0, float e1, float e2) {
		set(e0, e1, e2);
	}

    /**
     * 
     * @return
     */
    public native float x();
    public native float y();
    public native float z();

    /**
     * 
     * @param x
     */
    public native void setX(float x);
    public native void setY(float y);
    public native void setZ(float z);
    
    /**
     * 
     * @param x
     * @param y
     * @param z
     */
    public native void set(float x, float y, float z);

    /**
     * Negate vector.
     * @return
     */
    public native Vector3 negate();

    /**
     * 
     * @param index
     * @return
     */
    public native float get(int index);

    /**
     *	@return
     */
    public native float length();
    public native float squaredLength();

    /**
     *
     */
    public native void makeUnitVector();

    /**
     *
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
     *
     *	@return
     */
    public native Vector3 normalize();


    /**
     *	@return
     */
    public native Vector3 add(final Vector3 v1);
    public native Vector3 sub(final Vector3 v1);
    public native Vector3 div(final Vector3 v1);
    public native Vector3 div(final float f);
    public native Vector3 mul(final Vector3 v1);
    public native Vector3 mul(final float f);


    /**
     * 
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
     */
    @Override
    protected native Object clone();
    
    /**
     * 
     */
    @Override
    public native String toString();

    /**
     * 
     * @param v
     * @return
     */
    public native static Vector3 unitVector3(final Vector3 v);

	/**
	 * 
	 * @param v1
	 * @param v2
	 * @return
	 */
	public native static Vector3 minVec(final Vector3 v1, final Vector3 v2);

	/**
	 * 
	 * @param v1
	 * @param v2
	 * @return
	 */
	public native static Vector3 maxVec(final Vector3 v1, final Vector3 v2);

	/**
	 * 
	 * @param v1
	 * @param v2
	 * @return
	 */
	public native static Vector3 cross(final Vector3 v1, final Vector3 v2);

	/**
	 * 
	 * @param v1
	 * @param normal
	 * @return
	 */
	public native static Vector3 reflection(final Vector3 v1, final Vector3 normal);

	/**
	 * 
	 * @param v1
	 * @param normal
	 * @param refraction
	 * @return
	 */
	public native static Vector3 refraction(final Vector3 v1, final Vector3 normal, float refraction);

	/**
	 * 
	 * @param v1
	 * @param v2
	 * @return
	 */
	public native static float dot(final Vector3 v1, final Vector3 v2);

	/**
	 * 
	 * @param v1
	 * @param v2
	 * @param v3
	 * @return
	 */
	public native static float tripleProduct(final Vector3 v1, final Vector3 v2, final Vector3 v3);

	/**
	 * 
	 * @param normal
	 * @return
	 */
	public native static Vector3 tangent(final Vector3 normal);

	/**
	 * 
	 * @param normal
	 * @param tangent
	 * @return
	 */
	public native static Vector3 biTangent(final Vector3 normal, final Vector3 tangent);

	/**
	 * 
	 * @param normal
	 * @param tangent
	 * @return
	 */
	public native static Vector3 biNormal(final Vector3 normal, final Vector3 tangent);

	/**
	 * 
	 * @return
	 */
    public static Vector3 forward(){return new Vector3(0.0f, 0.0f, 1.0f);}
    public static Vector3 back(){return new Vector3(0.0f, 0.0f, -1.0f);}
    public static Vector3 right(){return new Vector3(1.0f, 0.0f, 0.0f);}
    public static Vector3 left(){return new Vector3(-1.0f, 0.0f, 0.0f);}
    public static Vector3 up(){return new Vector3(0.0f, 1.0f, 0.0f);}
    public static Vector3 down(){return new Vector3(0.0f, -1.0f, 0.0f);}
    public static Vector3 zero(){return new Vector3(0.0f, 0.0f, 0.0f);}


    /**
     *	Linear interpolation between v1 and v2 based on t.
     *	@return
     */
	public native static Vector3 lerp(Vector3 vec1, Vector3 vec2, float t);

    /**
     *	Spherical interpolation.
     *	@return
     */
    public native static Vector3 slerp(Vector3 vec1, Vector3 vec2, float t);
}
