/* Copyright (c) 2011-2017, EPFL/Blue Brain Project
 *                     Cyrille Favreau <cyrille.favreau@epfl.ch>
 *
 * This file is part of Paraballs and is based on the opengl-metaballs project
 * authored by Sierra Katow
 * https://github.com/sierrakatow/opengl-metaballs
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

#ifndef METABALLSGENERATOR_H
#define METABALLSGENERATOR_H

#include "Vec3f.h"
#include "TrianglesMesh.h"

#include <vector>
#include <stddef.h>
#include <limits>

namespace paraballs
{

const float inf = std::numeric_limits< float >::max();

struct Sphere
{
    vec3f center;
    float radius;
    size_t material;
};
typedef std::vector< Sphere > Spheres;

/**
 * Generates meshes according to given set of metaballs.
 */
class MetaballsGenerator
{

    struct SurfaceVertex
    {
        SurfaceVertex()
            : material( 0 )
        {}

        vec3f position;
        vec3f normal;
        vec3f textCoords;
        size_t material;
    };

    struct CubeGridVertex: public SurfaceVertex
    {

        CubeGridVertex()
            : SurfaceVertex()
            , value( 0.f )
        {}

        float value;
    };

    struct CubeGridCube
    {
        CubeGridVertex* vertices[8];
    };

    typedef std::vector< CubeGridVertex > Vertices;
    typedef std::vector< CubeGridCube > Cubes;
    typedef std::vector< SurfaceVertex > SurfaceVertices;

public:

    MetaballsGenerator() {}
    ~MetaballsGenerator();

    /** Generates a triangle based metaballs model according to provided
     * spheres, grid granularity and threshold
     *
     * @param metaballs spheres to generate the metaballs from
     * @param gridSize size of the grid
     * @param threshold points in 3D space that fall below the threshold
     *        (when run through the function) are ONE, while points above the
     *        threshold are ZERO
     * @param defaultMaterial default material to apply to the generated mesh
     * @param triangles generated triangles
     */
    void generateMesh(
            const Spheres& metaballs,
            const size_t gridSize,
            const float threshold,
            const size_t defaultMaterial,
            TrianglesMeshMap& triangles );

private:

    void _clear();

    void _buildVerticesAndCubes(
        const Spheres& metaballs,
        const size_t gridSize,
        const size_t defaultMaterial );

    void _buildTriangles(
        const Spheres& metaballs,
        const float threshold,
        TrianglesMeshMap& triangles );

    SurfaceVertices _edgeVertices;
    Vertices _vertices;
    Cubes _cubes;

};

}

#endif // METABALLSGENERATOR_H
