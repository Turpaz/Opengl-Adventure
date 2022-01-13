#pragma once

#include <glm/glm.hpp>
#include <math.h>

template<glm::length_t L, typename T, glm::qualifier Q>
glm::vec<L, T, Q> normalized(glm::vec<L, T, Q> const& x)
{
	glm::vec<L, T, Q> a = glm::normalize(x);
	bool valid = a.x == a.x && a.y == a.y && a.z == a.z;
	return (valid) ? glm::normalize(x) : glm::vec<L, T, Q>(0.f);
}