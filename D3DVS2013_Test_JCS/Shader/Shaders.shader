cbuffer ConstantBuffer 
{
    float3 Offset;
}

struct VOut 
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

VOut VShader(float4 position:Position, float4 color : COLOR) 
{
    // set up var
    VOut output;

    // set up values
    //-- POSITION --//
    output.position = position;
    //output.position.xy *= 0.7f;            // "shrink" the vertex on the x and y axes
    output.position.x += Offset.x;
    output.position.y += Offset.y;
    output.position.xy *= Offset.z;

    //-- COLOR --//
    output.color = color;
    //output.color.r *= RedLevel;            // set the red channel in each vertex
    //output.color.b *= BlueLevel;        // set the blue channel in each vertex
    //output.color.r = 1.0f;            // NOTE: change this after warm color appeared!!!

    //return values
    return output;
}

float4 PShader(float4 position:SV_POSITION, float4 color : COLOR) : SV_TARGET 
{
    return color;
}

