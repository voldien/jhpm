/**
 * High performance matrix library wrapper, utilizing SIMD extensions.
 * Copyright (C) 2017  Valdemar Lindberg
 * <p>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * <p>
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * <p>
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package org.jhpm;

import java.util.Arrays;
import java.util.Objects;

/**
 * Matrix3x3, contains three rows for which
 * each contains four elements.
 *
 * @author Valdemar Lindberg
 */
public class Matrix3x3 {

    private float[] e;

    public Matrix3x3() {
        e = new float[16];
    }

    public Matrix3x3(Matrix3x3 m) {
    }

    public Matrix3x3(Matrix4x4 m) {
    }

    /**
     * Calculate the determinant.
     *
     * @return
     */
    public native float determinant();

    /**
     * @return
     */
    public native Matrix3x3 inverse();

    /**
     * @return
     */
    public native boolean isIdentity();

    /**
     *
     */
    public native void identity();

    /**
     * @return
     */
    public native Matrix3x3 transpose();

    /**
     * @param index
     * @return
     */
    public native Vector3 get(int index);

    /**
     * @param i
     * @param j
     * @return
     */
    public native float get(int i, int j);

    /**
     * @param v1
     * @return
     */
    public native Matrix3x3 add(Matrix3x3 v1);

    /**
     * @param v1
     * @return
     */
    public native Matrix4x4 sub(Matrix3x3 v1);

    /**
     * @param v1
     * @return
     */
    public native Matrix3x3 mul(Matrix3x3 f1);

    /**
     * @param v1
     * @return
     */
    public native Vector3 mul(final Vector3 f1);

    /**
     * @return
     */
    @Override
    public native boolean equals(Object obj);

    /**
     * @Return
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
