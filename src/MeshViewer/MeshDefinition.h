#ifndef MESHDEFINITION_H
#define MESHDEFINITION_H

#include <OpenMesh/Core/Geometry/VectorT.hh>
//#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
struct Mesh_Feature
{//ground-truth feature
	Mesh tri;
	vector<int> V_map, V_map_reverse;

	vector<Vector3d> Tcenters;
	double ave_length;
	double angle_threshold = 0;
	bool orphan_curve = true;
	bool orphan_curve_single = true;
	//read_from_file 
	bool read_from_file = false;
	vector<vector<uint32_t>> IN_v_pairs;
	vector<uint32_t> IN_corners;
	vector<bool> E_feature_flag;

	vector<uint32_t> corners;
	vector<vector<uint32_t>> corner_curves;


	vector<vector<uint32_t>> curve_vs;
	vector<vector<uint32_t>> curve_es;
	vector<bool> broken_curves;
	vector<bool> circles;//true -- circle, false -- not circle

	MatrixXd normal_V, normal_Tri;

	vector<int> v_types;//Regular --> V, edge -- curve id, corner -- V
};
struct MeshTraits : public OpenMesh::DefaultTraits
{
	typedef OpenMesh::Vec3d Point;
	typedef OpenMesh::Vec3d Normal;

	VertexAttributes(OpenMesh::Attributes::Status);
	FaceAttributes(OpenMesh::Attributes::Status);
	EdgeAttributes(OpenMesh::Attributes::Status);
	HalfedgeAttributes(OpenMesh::Attributes::Status);

	FaceTraits
	{
	};

	EdgeTraits
	{
	};

	HalfedgeTraits
	{
		HalfedgeT() :face_he_var(-1)
		{
		};
	private:
		int face_he_var;
	public:
		int get_face_he_var() { return face_he_var; };
		void set_face_he_var(int fhe) { face_he_var = fhe; };
	};

	VertexTraits
	{
		VertexT() : new_pos_fixed(false)
		{
		};
	private:
		OpenMesh::Vec3d new_pos;//can be used for deformation and parameterization
		bool new_pos_fixed;
	public:
		void set_New_Pos(const OpenMesh::Vec3d& n_p){ new_pos = n_p; };
		OpenMesh::Vec3d& get_New_Pos(){ return new_pos; };
		void set_new_pos_fixed(bool f){ new_pos_fixed = f; };
		bool get_new_pos_fixed(){ return new_pos_fixed; };
	};

};

//typedef OpenMesh::TriMesh_ArrayKernelT<MeshTraits> Mesh;
typedef OpenMesh::PolyMesh_ArrayKernelT<MeshTraits> Mesh;

bool is_flip_ok_openmesh(Mesh::EdgeHandle& eh, Mesh& mesh_);//just copy the code from openmesh
bool flip_openmesh(Mesh::EdgeHandle& eh, Mesh& mesh_);

bool check_in_triangle_face(const std::vector<OpenMesh::Vec3d>& tri, const OpenMesh::Vec3d& p);


#endif