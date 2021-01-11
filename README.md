# Framework for surface mesh processing

The program is used to load meshes and render using OpenGL.

## External Libraries

* [Eigen](http://eigen.tuxfamily.org/)
* [OpenMesh](https://www.openmesh.org/), Recommended version: the latest 8.1(at Oct. 2020)
* [Qt](https://www.qt.io/), Recommended version: 5.13.0

## Usage

```
git clone https://github.com/USTC-GCL-F/Surface-Mesh-Framework
cd SurfaceFramework
```

Edit lines 7-9 of CmakeLists.txt to set the values of **EIGEN_PATH**,**OPENMESH_PATH** and **OPENMESH_LIB_PATH**
```
mkdir build && cd build
cmake -A x64 ..
```

Open **SurfaceFramework.sln**, select **SrufaceFramework** as launch project, and run.


## Supported File Formats

.obj .off .ply .stl# Surface-Mesh-Framework-windows

## 可以读取特征点和特征边文件

先选中特诊边和特征点的选取按键，然后点击读取相关特征文件


