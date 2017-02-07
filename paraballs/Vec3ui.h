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

#ifndef VEC3UI_H
#define VEC3UI_H

namespace paraballs
{

struct vec3ui
{
    vec3ui( const unsigned int x, const unsigned int y, const unsigned int z )
        : x(x), y(y), z(z)
    {}

    vec3ui()
        : x(0), y(0), z(0)
    {}

    unsigned int x;
    unsigned int y;
    unsigned int z;
};

}

#endif // VEC3UI_H
