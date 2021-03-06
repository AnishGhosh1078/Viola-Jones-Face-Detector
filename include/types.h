#pragma once

#include <vector>
#include <memory>
#include <thread>
#include <math.h>
#include "opencv2/opencv.hpp"
#include <opencv2/videoio.hpp>
#include "opencv2/opencv.hpp"
#include <opencv2/core/mat.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include <time.h>

using namespace cv;
using namespace std;

#ifdef _WIN32
	using byte	= unsigned __int8;
	using word	= unsigned __int16;
	using dword	= unsigned __int32;
	using qword	= unsigned __int64;
#else
	using byte	= uint8_t;
	using word	= uint16_t;
	using dword	= uint32_t;
	using qword	= uint64_t;
#endif

static const double	Pi	= 3.1415926;			///< Pi number
static const float	Pif	= 3.1415926f;			///< Pi number
