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

    /**
     * Create default vector3 object
     * instance.
     */
    Vector3() {
        e = new float[3];
    }

    /**
     * Set aligned vector value.
     *
     * @param val aligned vector value.
     */
    Vector3(float val) {
        e = new float[3];
        setX(val);
        setY(val);
        setZ(val);
    }

    /**
     * @param e0
     * @param e1
     * @param e2
     */
    Vector3(float e0, float e1, float e2) {
        set(e0, e1, e2);
    }

    /**
     * @param v
     * @return
     */
    public native static Vector3 unitVector3(final Vector3 v);

    /**
     * @param v1
     * @param v2
     * @return
     */
    public native static Vector3 minVec(final Vector3 v1, final Vector3 v2);

    /**
     * @param v1
     * @param v2
     * @return
     */
    public native static Vector3 maxVec(final Vector3 v1, final Vector3 v2);

    /**
     * @param v1
     * @param v2
     * @return
     */
    public native static Vector3 cross(final Vector3 v1, final Vector3 v2);

    /**
     * @param v1
     * @param normal
     * @return
     */
    public native static Vector3 reflection(final Vector3 v1, final Vector3 normal);

    /**
     * @param v1
     * @param normal
     * @param refraction
     * @return
     */
    public native static Vector3 refraction(final Vector3 v1, final Vector3 normal, float refraction);

    /**
     * @param v1
     * @param v2
     * @return
     */
    public native static float dot(final Vector3 v1, final Vector3 v2);

    /**
     * @param v1
     * @param v2
     * @param v3
     * @return
     */
    public native static float tripleProduct(final Vector3 v1, final Vector3 v2, final Vector3 v3);

    /**
     * @param normal
     * @return
     */
    public native static Vector3 tangent(final Vector3 normal);

    /**
     * @param normal
     * @param tangent
     * @return
     */
    public native static Vector3 biTangent(final Vector3 normal, final Vector3 tangent);

    /**
     * @param normal
     * @param tangent
     * @return
     */
    public native static Vector3 biNormal(final Vector3 normal, final Vector3 tangent);

    /**
     * @return
     */
    public static Vector3 forward() {
        return new Vector3(0.0f, 0.0f, 1.0f);
    }

    public static Vector3 back() {
        return new Vector3(0.0f, 0.0f, -1.0f);
    }

    public static Vector3 right() {
        return new Vector3(1.0f, 0.0f, 0.0f);
    }

    public static Vector3 left() {
        return new Vector3(-1.0f, 0.0f, 0.0f);
    }

    public static Vector3 up() {
        return new Vector3(0.0f, 1.0f, 0.0f);
    }

    public static Vector3 down() {
        return new Vector3(0.0f, -1.0f, 0.0f);
    }

    public static Vector3 zero() {
        return new Vector3(0.0f, 0.0f, 0.0f);
    }

    /**
     * Linear interpolation between v1 and v2 based on t.
     *
     * @return
     */
    public native static Vector3 lerp(Vector3 vec1, Vector3 vec2, float t);

    /**
     * Spherical interpolation.
     *
     * @return
     */
    public native static Vector3 slerp(Vector3 vec1, Vector3 vec2, float t);

    /**
     * Get X component of the vector.
     *
     * @return value of x.
     */
    public native float x();

    /**
     * Get Y component of the vector.
     *
     * @return value of y.
     */
    public native float y();

    /**
     * Get Z component of the vector.
     *
     * @return value of z.
     */
    public native float z();

    /**
     * Set x component of the vector.
     *
     * @param x
     */
    public native void setX(float x);

    /**
     * Set y component of the vector.
     *
     * @param y
     */
    public native void setY(float y);

    /**
     * Set Z component of the vector.
     *
     * @param z
     */
    public native void setZ(float z);

    /**
     * Set all components of the vector.
     *
     * @param x component.
     * @param y component.
     * @param z component.
     */
    public native void set(float x, float y, float z);

    /**
     * Compute negated vector.
     *
     * @return negated vector.
     */
    public native Vector3 negate();

    /**
     * @param index
     * @return
     */
    public native float get(int index);

    /**
     * Comput the length of the vector.
     *
     * @return non-negative number.
     */
    public native float length();

    /**
     * Compute length square of the vector.
     *
     * @return non-negative number.
     */
    public native float squaredLength();

    /**
     * Compute and set vector a normalized
     * vector.
     */
    public native void makeUnitVector();

    /**
     * @return
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
     * @return
     */
    public native Vector3 normalize();

    /**
     * @return
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
}
