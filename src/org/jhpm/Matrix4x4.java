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
 * Matrix4x4, contains four rows for which
 * each contains four elements.
 *
 * @author Valdemar Lindberg
 */
public class Matrix4x4 {
	
	private float[] e;

	/**
	 *
	 */
	public Matrix4x4(){
		this.e = new float[16];
	}

	/**
	 * Check if matrix is an identity matrix.
	 * @return
	 */
	public native boolean isIdentity();

	/**
	 * Compute determinant of the matrix.
	 * @return
	 */
	public native float determinant();

	/**
	 * Compute the inverse vector
	 * if possible.
	 * @return inversed matrix.
	 */
	public native Matrix4x4 inverse();

	/**
	 * Transpose matrix.
	 * @return transposed matrix.
	 */
	public native Matrix4x4 transpose();

	/**
	 * Get element by index.
	 * @param index.
	 * @return nth column.
	 */
	public native Vector4 get(int index);
	
	/**
	 * 
	 * @param i
	 * @param j
	 * @return
	 */
	public native float get(int i, int j);

	/**
	 * Add matrix.
	 * @param v1
	 * @return
	 */
	public native Matrix4x4 add(final Matrix4x4 v1);
	/**
	 * 
	 * @param v1
	 * @return
	 */
	public native Matrix4x4 sub(final Matrix4x4 v1);
	/**
	 * 
	 * @param f1
	 * @return
	 */
	public native Matrix4x4 mul(Matrix4x4 f1);
	
	/**
	 * 
	 * @param f
	 * @return
	 */
	public native Matrix4x4 mul(float f);
	
	/**
	 * 
	 * @param f1
	 * @return
	 */
	public native Vector4 mul(final Vector4 f1);

	/**
	 * 
	 */
	@Override
	protected native Object clone();

	/**
	 * Compare two matrices and check
	 * if equal
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
	 * Convert matrix to string.
	 * @Return
	 */
	@Override
	public native String toString();
	
	 /**
	  *	Create translation matrix.
	  * @param x position in X axis.
	  * @param y position in Y axis.
	  * @param z position in Z axis.
	  * @return Translation matrix.
	  */
	public native static Matrix4x4 translate(float x, float y, float z);

	/**
	 *	Create translation matrix.
	 *
	 *	@return translated matrix
	 */
	public native static Matrix4x4 translate(Vector3 translation);

	/**
	 *	Create rotation matrix from angle around the axis.
	 *
	 *	@return rotation matrix.
	 */
	public native static Matrix4x4 rotate(float angle, Vector3 axis);

	/**
	 * Create rotation matrix from quaternion.
	 *
	 * @return rotation matrix.
	 */
	public static native Matrix4x4 rotate(Quaternion quat);

	/**
	 *	Create scale matrix.
	 *
	 *	@return scale matrix.
	 */
	public native static Matrix4x4 scale(float x, float y, float z);

	/**
	 * Create scale matrix.
	 * @param scale
	 * @return
	 */
	public native static Matrix4x4 scale(Vector3 scale);

	/**
	 * Create perspective matrix.
	 * @param fov angle in radius
	 * @param aspect image view ratio.
	 * @param near 
	 * @param far
	 * @return perspective matrix.
	 */
	public native static Matrix4x4 perspective(float fov, float aspect, float near,
			float far);

	/**
	 * Create look at orientation translated
	 * matrix.
	 *
	 * @param lookPosition
	 * @param position transformation in world space.
	 * @param forward
	 * @return
	 */
	public native static Matrix4x4 lookAt(Vector3 lookPosition,
				Vector3 position, Vector3 forward);

	/**
	 * Create orthographic perspectice.
	 * @param left
	 * @param right
	 * @param bottom
	 * @param top
	 * @param near
	 * @param far
	 * @return
	 */
	public native static Matrix4x4 orth(float left, float right, float bottom, float top,
			float near, float far);

	/**
	 *	Create bias matrix.
	 * @return
	 */
	public native static Matrix4x4 biasMatrix();

	/**
	 * Create identity matrix.
	 * @return identity matrix. 
	 */
	public native static Matrix4x4 identity();

}
