
//---- NVCC compiler will compile
//---- Generates PTX file format using CUDA compiler
__global__ void AddKernel(int a , int b, int *result )

{

*result = a + b;

}



/////////////////////////////////////

//

// main - CPU entry point ....

//

//



int main( int argc, char **argv )

{

int result; // to store CPU int...



int *dev_result; // to store the GPU int...



// --------- Allocate memory for the device result...

// --------- Let us assume that function won't fail...



cudaMalloc( (void**)&dev_result,sizeof(int));



//----------- invoke the Kernel Function...

//----------- __global__ gives a hint to nvcc that 

//----------- the stuff has to be compiled by GPU compiler



AddKernel<<<1,1>>>( 2, 7, dev_result ); 



//----------- Copy the dev_result from GPU memory to 

//----------- CPU memory 



cudaMemcpy( &result,

dev_result,

sizeof(int),

cudaMemcpyDeviceToHost ); 







printf( "%d + %d = %d\n",2,7,result );





cudaFree( dev_result );



return 0;





}
