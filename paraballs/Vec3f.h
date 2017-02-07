/* Copyright (c) 2011-2017, EPFL/Blue Brain Project
 *                     Cyrille Favreau <cyrille.favreau@epfl.ch>
 *
 * This file is part of Paraballs
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#ifndef VEC3F_H
#define VEC3F_H

#include <math.h>

namespace paraballs
{

struct vec3f
{
    vec3f( const float x, const float y, const float z )
        : x(x), y(y), z(z)
    {}

    vec3f()
        : x(0.f), y(0.f), z(0.f)
    {}

    float length() const
    {
        return sqrt( x * x + y * y + z * z );
    }

    vec3f normalized() const
    {
        const float l = length();
        if( l != 0.f )
            return vec3f( x / l, y / l, z / l );
        else
            return vec3f( 0.f, 0.f, 0.f );
    }

    vec3f operator-( const vec3f& v ) const
    {
        return vec3f( v.x - x, v.y - y, v.z - z );
    }

    vec3f operator+( const vec3f& v ) const
    {
        return vec3f( v.x + x, v.y + y, v.z + z );
    }

    float x;
    float y;
    float z;
};

inline vec3f operator*( const float t, const vec3f& v )
{
    return vec3f( v.x * t, v.y * t, v.z * t );
}

inline vec3f operator/( const float t, const vec3f& v )
{
    return vec3f( v.x / t, v.y / t, v.z / t );
}

}

#endif // VEC3F_H
