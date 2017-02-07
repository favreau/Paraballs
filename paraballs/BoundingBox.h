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

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

namespace paraballs
{

struct BoundingBox
{
    BoundingBox()
        : lower( inf, inf, inf )
        , upper(-inf, -inf, -inf)
    {}

    void extend( const vec3f& value )
    {
        lower.x = std::min( lower.x, value.x );
        lower.y = std::min( lower.y, value.y );
        lower.z = std::min( lower.z, value.z );

        upper.x = std::max( upper.x, value.x );
        upper.y = std::max( upper.y, value.y );
        upper.z = std::max( upper.z, value.z );
    }

    vec3f center() const
    {
        return vec3f(
            ( lower.x + upper.x ) / 2.f,
            ( lower.y + upper.y ) / 2.f,
            ( lower.z + upper.z ) / 2.f );
    }

    vec3f size() const
    {
        return vec3f(
            upper.x - lower.x,
            upper.y - lower.y,
            upper.z - lower.z );
    }

    vec3f lower;
    vec3f upper;
};

}

#endif // BOUNDINGBOX_H
