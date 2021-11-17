# MiniRT

<p align="center">
<img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/stdvsbrdf.png?raw=true"></img>
</p>
Graphics project for Codam / 42 school, my first ray tracer using MinilibX.

**Project goal:**
>The goal of your program is to generate images
using the Raytracing protocol.  Those computer generated images will each represent a scene, as seen from a specific angle and position, defined by simple geometric objects, and each with its own lighting system.

**Project Grade: 115**

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
|R| | | | |640|360|
|A| | |0.25| | | |255,255,255|
|c|0,0,-10|0,0,1|65.0|
|l|0,10,10| |0.75| | | |255,255,255|
|pl|0,0,0|0,1,0| | | | |129,22,255|
|sp|0,1.25,0| | |2.5| | |129,22,90|
|sq|-1,4,2|1,1,-1|5| | | |129,255,90|
|cy|1,2,-2|-0.2,0.3,1| |3| |10|129,255,90|
|tr|0,0,0 2,5,0 0,3,-5| | | | | |255,255,255|

<details>
<summary>Bonus scene syntax</summary>
 
**Anti aliasing**:
| ID  | Samples per pixel | Sobel accelerate (best on untextured shapes) |
|-|-|-|
| AA | 16 | 1 |

**BRDF rendering**:
| ID  | Samples per pixel (times four) | Scene bounces | Save after rendering (optional) |
|-|-|-|-|
| BRDF | 16 | 4 | --save |

**Viewport resolution**:
| ID  | Value (full, half, quarter |
|-|-|
| VP | full |

**Skybox**:
| ID  | Path | Emission (brdf only) | De-gamma |
|-|-|-|-|
| SKY | "textures/sky.xpm" | 10 | 1 |

**Sun (brdf only)**:
| ID  | Direction | Emission | scale |
|-|-|-|-|
| SUN | 1,1,0 | 27 | 0.4 |

**Multi threading**:
| ID  | Count |
|-|-|
| THREADS | 4 |

**Wavefront OBJ**:
| ID  | Path | Origin | Color |
|-|-|-|-|
| obj | "wavefront/suzanne.obj" | 0,0,0 | 255,255,255 |

**Shapes & elements**:
| ID  | origin | orientation | Scale | Height | Color | Material (optional) |
|-|-|-|-|-|-|-|
| ds | 0,1,0 | 0.577,0.577,0.577 | 5.2 | | 255,255,255 | -mat "materials/specular.mat" |
| cb | 1,1,1 | 0.77,0.77,1 | 3 | | 255,255,255 | -mat "materials/cube.mat" |
| py | 0,0,0 | -1,1,-1 | 3 | 5 | 127,128,127 | -mat "materials/pyramid.mat" |
| cyc | 0,0,0 | 0,1,0 | 2 | 5 | 127,93,220 | -mat "materials/cylinder_cap.mat" |
| lp | 0,10,0 | 0,-1,0 | 0.3 | | 255,255,255 | |
</details>

[Bonus scenes](https://github.com/gmzorz/MiniRT/tree/main/scenes/bonus)

### Keybinds
Keybinds can be found in [key.c](https://github.com/gmzorz/MiniRT/blob/main/sources/jump/key.c) for the mandatory part, or [key_bonus.c](https://github.com/gmzorz/MiniRT/blob/main/sources/jump/key_bonus.c) for the bonus part. The same goes for [mouse_bonus.c](https://github.com/gmzorz/MiniRT/blob/main/sources/jump/mouse_bonus.c)
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
* `Space` - Render BRDF
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

Bonuses handled (15):
* Normal disruption using sine over UV coordinates
* Color disruption: checkerboard pattern
* Color disruption: rainbow effect using object's normal
* Parallel light following a precise dirxection
* Compound element: Cube (six squares)
* Compound element: Pyramid (four triangles, one square)
* Caps on cylinders (disks)
* One color filter: Gamma correction & Sobel edge detection
* Anti Aliasing
* Multithreaded rendering
* Sphere texturing: uv mapping (fixed to work with all shapes)
* Handle bump map textures (Normal map)
* A beautiful skybox
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

# Materials

Materials can be applied to any shape using the `-mat` flag, followed by a file path `"dir/file.mat"` written directly behind the color input. Materials allow for the customization of reflections, specularity, gloss, emission, normal transformation and emission. We can also specify custom textures to map these values according to their respective UV coordinates.

The following table shows an example of a valid `.mat` syntax, and which materials can be used on what render mode (checkmark indicators are excluded from the actual .mat file (EOL = End Of Line), see: [Materials](https://github.com/gmzorz/MiniRT/tree/main/materials)). For clarification, **Gloss** and **roughness** are almost the same, however gloss affects the specular exponent used to generate a *shine* effect in the classic ray tracer. the input is linear, and is computed to match the exponent value. The roughness BRDF value determines the mix between diffuse and reflection, which results in the shape's gloss level (0.0 being fully reflective & glossy, whereas gloss in classic tracing has a maximum value of 1.0 being the gloss amount. **Specularity** is the blending value between diffuse and gloss, and **reflection** is the blending value between diffuse and reflected rays. **emmission** allows for the shape to emit light instead of absorb it. Color blend for emission is not capped to any value
ID|flags|Amount|Color blend| |Classic|BRDF|
-|-|-|-|-|-|-|
diffuse| | | 255,128,128 | `EOL` | ✅ | ✅ |
specular| | | 255,255,255 | `EOL` | ✅ | ❌ |
reflection| | | 255,255,255 | `EOL` | ✅ | ✅ |
gloss | | 0.5 | | `EOL` | ✅ | ❌ |
roughness | | 0.5 | | `EOL` | ❌ | ✅ |
emission | | | 100,100,100 | `EOL` | ❌ | ✅ |

We can map these values according to UV coordinates by loading image textures. This is also where **normal maps** come in, they are however only "valid" on classic ray tracing. A BRDF uses a randomization monte carlo algorithm, so in certain cases this will invalidate the use of normal maps because rays can end up facing in directions that point inwards of a shape. This issue is not being dealt with, some normal maps can apply to a BRDF mixed with the right roughness values. Gloss values can be mapped as well, but in most cases i invert the roughness channel in order to get a valid gloss map, the same can be done the opposite way.
|ID|Path to texture file|
|-|-|
diffuse_map	|	"textures/stained_dif.xpm" |
normal_map	|	"textures/stained_nml.xpm" |
roughness_map	| "textures/stained_rgh.xpm" |
reflection_map	| "textures/stained_rfl.xpm" |
specular_map	| "textures/stained_spc.xpm" |
emission_map | "textures/stained_ems.xpm" |

Other material properties include the sine wave bonus, and the option to scale textures' width and height:
|ID|flag (u/v/uv) |Amplitude|Frequency|
|-|-|-|-|
wave | uv | 0.5 | 100 |

|ID| Scale |
|-|-|
scale_x | 0.5 |
scale_y | 1.2 |

# Depth of field

One of the things i personally enjoy is a good **Bokeh**, this describes the circular shape of the depth of field in cameras, as well as anamorphic ellipse-type shapes. Both of these have been implemented using the appropriate sampling methods, as well as a rejection method for custom lens shapes

<img src="https://github.com/gmzorz/MiniRT/blob/main/screenshots/Tue Feb 16 18:49:24 2021.bmp?raw=true" width="256" height="256"></img>
