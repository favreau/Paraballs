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

#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H

#include <vector>
#include <map>

#include "Vec3f.h"
#include "Vec3ui.h"

namespace paraballs
{

struct TrianglesMesh
{
    std::vector< vec3f > vertices;
    std::vector< vec3f > texCoords;
    std::vector< vec3f > normals;
    std::vector< vec3ui > indices;
};

typedef std::map< size_t, TrianglesMesh > TrianglesMeshMap;

}

#endif // TRIANGLEMESH_H
