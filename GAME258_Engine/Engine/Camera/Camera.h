#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

//#include "../Math/Frustum.h"
#include "../FX/LightSource.h"

using namespace glm;
using namespace std;

class Camera
{
public:
	Camera();
	~Camera();

	void AddLight(LightSource* light_);

	//Getters
	inline mat4 GetView() const { return view; }
	inline mat4 GetPerspective() const { return perspective; }
	inline mat4 GetOrthograpic() const { return orthographic; }
	inline vec3 GetPosition() const { return position; }
	inline float GetNearPlane() const { return nearPlane; }
	inline float GetFarPlane() const { return farPlane; }
	//inline Frustum GetFrustum() const { return frustum; }
	inline vector<LightSource*> GetLights() const { return lights; }

	//Setters
	//Set the given value, then update the camera's vectors to be proper.
	inline void SetPosition(vec3 position_) {
		position = position_;
		UpdateCameraVectors();
	}
	inline void SetRotation(float yaw_, float pitch_) {
		yaw = yaw_; 
		pitch = pitch_;
		UpdateCameraVectors();
	}

	void ProcessMouseMovement(vec2 offset_);
	void ProcessMouseZoom(int y_);
private:
	void UpdateCameraVectors();
	vec3 position;
	mat4 perspective, orthographic, view;
	float fieldOfView;
	float yaw, pitch;
	float nearPlane, farPlane;
	vec3 forward, up, right, worldUp;
	
	//Frustum* frustum;
	vector<LightSource*> lights;
};

#endif // !CAMERA_H