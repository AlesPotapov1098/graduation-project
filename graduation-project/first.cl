__kernel void TestKernel(
	__global const float* pInputVector1, 
	__global const float* pInputVector2, 
	__global float* pOutputVectorHost, 
	int elementsNumber)
{
    int iJob = get_global_id(0);

    if (iJob >= elementsNumber) 
		return; 

    pOutputVectorHost[iJob] = pInputVector1[iJob] + pInputVector2[iJob];
}