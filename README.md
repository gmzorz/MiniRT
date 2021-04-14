# MiniRT

<img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/stdvsbrdf.png?raw=true" width="960" height="384"></img>
Graphics project for Codam / 42 school, my first ray tracer using MinilibX.

**Project goal:**
>The goal of your program is to generate images
using the Raytracing protocol.  Those computer generated images will each represent a scene, as seen from a specific angle and position, defined by simple geometric objects, and each with its own lighting system.

# Compiling
running `make` will compile the mandatory part, `make bonus` will overwrite and add the bonus. `make clean` or `make fclean` can be used to wipe binaries

# Usage
Run using: `./MiniRT path/to/file.rt` or `./MiniRT path/to/file.rt --save` to render and save the image.
MiniRT supports files suffixed with the **.rt** extension. All rules from the PDF apply.
The two shell scripts in the root of this directory will run tests (using scenes/../error) to ensure these errors are handled properly.

### Scenes
Shapes and elements can be defined in the scene (.rt) files. a simple scene with all elements may look like this:
| ID  | Origin | Orientation | Scale | Radius | width | Height | Color |
|-|-|-|-|-|-|-|-|
|R|-|-|-|-|640|360|-|
|A|-|-|0.25|-|-|-|255,255,255|
|c|0,0,-10|0,0,1|65.0|-|
|l|0,10,10|-|0.75|-|-|-|255,255,255|
|pl|0,0,0|0,1,0|-|-|-|-|129,22,255|
|sp|0,1.25,0|-|-|2.5|-|-|129,22,90|
|sq|-1,4,2|1,1,-1|5|-|-|-|129,255,90|
|cy|1,2,-2|-0.2,0.3,1|-|3|-|10|129,255,90|
|tr|0,0,0 2,5,0 0,3,-5|-|-|-|-|-|255,255,255|

### Keybinds
Keybinds can be found in [key.c](https://github.com/gmzorz/MiniRT/blob/main/sources/jump/key.c) for the mandatory part, or [key_bonus.c](https://github.com/gmzorz/MiniRT/blob/main/sources/jump/key_bonus.c) for the bonus part.
<details>
<summary>key.c</summary>
  
* `Escape` - Exit program
* `Enter` - Render scene
* `1` - Render image using flat shading
* `2` - Render image using unlit colors
* `3` - Debug bounding volumes
* `Comma` - Previous camera
* `Dot` - Next camera
</details>

<details>
<summary>key_bonus.c</summary>
  
* `Escape` - Exit program
* `Enter` - Render scene
* `1` - Render image using flat shading
* `2` - Render image using unlit colors
* `3` - Debug bounding volumes
* `4` - Debug Normals (Rainbow color bonus)
* `5` - Debug Units (Checkerboard pattern bonus)
* `6` - Debug UVs
* `7` - Debug DOF
* `Comma` - Previous camera
* `Dot` - Next camera
* `W` - Move forward
* `A` - Move left
* `S` - Move back
* `D` - Move right
* `Q` - Move down
* `E` - Move up
* `J` - Pan left
* `K` - Pan down
* `I` - Pan up
* `L` - Pan right
* `U` - Roll left
* `O` - Roll right
* `T` - Translation mode: edit position (if shape is selected)
* `R` - Translation mode: edit rotation (if shape is selected)
* `X` - Translation axis: X
* `Y` - Translation axis: Y
* `Z` - Translation axis: Z
* `Up` - Translate in the positive direction (if translation axis is set)
* `Down` - Translate in the negative direction (if translation axis is set)
* `Plus` - Increase FOV
* `Minus` - Decrease FOV
* `Shift` - Take screenshot
</details>

<details>
<summary>mouse_bonus.c</summary>
  
* `Mouse1` - Select shape
* `Mouse2` - Deselect shape
* `Mouse4` - move the depth of field focal plane forward (BRDF only)
* `Mouse5` - move the depth of field focal plane back (BRDF only)
</details>

# Debug modes

<img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/Mon%20Apr%2012%2022:28:26%202021.png?raw=true" width="150" height="150"></img>
<img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/Mon%20Apr%2012%2022:28:28%202021.png?raw=true" width="150" height="150"></img>
<img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/Mon%20Apr%2012%2022:28:31%202021.png?raw=true" width="150" height="150"></img>
<img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/Mon%20Apr%2012%2022:28:32%202021.png?raw=true" width="150" height="150"></img>
<img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/Mon%20Apr%2012%2022:28:33%202021.png?raw=true" width="150" height="150"></img>

Left to right: Flat, unlit, normals, units and UVs

# About
The mandatory part of the project requires you to code a classic one-ray-per-pixel style ray tracer. However for the bonus part of MiniRT i implemented a **BRDF** rendering equation to render more realistic looking scenes. This includes Global illumination, roughness materials, soft shadows and depth of field sampling. Another neat little feature is the rendering of complex `.obj` triangle meshes, using a BVH acceleration structure. Other fun things include material loading on top of the standard 8bit color defines.


  <img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/stanford_dragon.png?raw=true" width="200" height="200"></img>
  <img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/anamorphic_blur.png?raw=true" width="200" height="200"></img>
  <img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/forest.png?raw=true" width="200" height="200"></img>
  <img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/artsy.png?raw=true" width="200" height="200"></img>


MiniRT uses MinilibX, a small graphics library that allows for simple window management and putting pixels to the screen.
The program can render the following shapes and scene elements using their respective identifiers:
<details>
<summary>Mandatory:</summary>
  
* `R`   - Window resolution
* `A`   - Ambient lighting
* `l`   - Point light
* `c`   - Camera
* `pl`  - Plane
* `sp`  - Sphere
* `cy`  - Cylinder (non-capped)
* `sq`  - Square
* `tr`  - Triangle
</details>

<details>
<summary>Bonus:</summary>
  
* `SKY` - Skybox loading
* `SUN` - Sun rendering (emission BRDF only)
* `THREADS` - Multithreaded rendering (BRDF only)
* `AA`  - Anti aliasing (Classic shading only), option to accelerate
* `VP`  - Viewport resolution (downscaling for faster debugging)
* `cb`  - Cube (6 squares)
* `py`  - Pyramid (One square, four triangles)
* `ds`  - Disk
* `cyc` - Capped cylinders
* `obj` - Triangle mesh
* `lp`  - Parallel light (fixed direction)

More about these identifiers can be found in the [scenes](https://github.com/gmzorz/MiniRT/edit/main/scenes/bonus) directory
</details>



Other bonus subjects handled are:
* Normal disruption using sine over UV coordinates
* Color disruption: checkerboard pattern
* Color disruption: rainbow effect using object's normal
* One color filter: Gamma correction & Sobel edge detection
* Sphere texturing: uv mapping
* Shape texturing: uv mapping (All other shapes)
* Handle bump map textures (Normal map)
* Keyboard interactivity (translation/rotation) with the camera
* Keyboard interactivity (translation/rotation) with shapes

# Mesh loading
Mesh loading is simple and limited, MiniRT will only parse vertices and triangulated faces. Vertex normals are computed by the program itself. 
an example of a working .obj file would be:
```# Blender v2.92.0 OBJ File: ''
# www.blender.org
o dragon
v -0.090499 -0.115513 -0.093754
v -0.090303 -0.116237 -0.093008
v -0.090556 -0.115490 -0.093008
...
...
f 1 2 3
f 4 1 3
f 5 1 4
```
In blender, the export settings can include modifiers but the output **has** to be triangulated.

<img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/bvh_car_1m.png?raw=true" width="640" height="360"></img>

The model above consists of over 1.000.000 triangles, rendering these triangles is done through a Bounding Volume Hierarchy octree structure, which means the intersection tests are narrowed down and allows for faster rendering. I have attempted to make a comparison, but as it turns out.. rendering 1M triangles without a BVH structure is just not really what you want to be waiting on.

# Depth of field

One of the things i personally enjoy is a good **Bokeh**, this describes the circular shape of the depth of field in current day cameras, as well as anamorphic ellipse-type shapes. Both of these have been implemented using the appropriate sampling methods, as well as a rejection method for custom lens shapes

<img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/Tue Feb 16 18:49:24 2021.bmp?raw=true" width="512" height="512"></img>
