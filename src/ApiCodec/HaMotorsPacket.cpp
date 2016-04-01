#include "HaMotorsPacket.hpp"
#include "vitals/CLByteConversion.h"

//=============================================================================
//
HaMotorsPacket::HaMotorsPacket( )
{

}

//=============================================================================
//
HaMotorsPacket::HaMotorsPacket( int8_t left_, int8_t right_ )
	: 	left{ left_ },
		 right{ right_ }
{

}

//=============================================================================
//
HaMotorsPacket::~HaMotorsPacket( )
{

}

//=============================================================================
//
cl::BufferUPtr HaMotorsPacket::encode()
{
	uint cpt = 0;

	cl::BufferUPtr buffer = cl::unique_buffer( 2 );

	(*buffer)[cpt++] = static_cast<uint8_t>( left );
	(*buffer)[cpt++] = static_cast<uint8_t>( right );

	return std::move( getPreparedBuffer( std::move( buffer ), getPacketId() ) );
}

//=============================================================================
//
void HaMotorsPacket::decode( uint8_t *buffer, uint bufferSize )
{
	ignore( bufferSize );

	uint cpt = getStartPayloadIndex();

	left = static_cast< int8_t >( buffer[ cpt++ ] );
	right = static_cast< int8_t >( buffer[ cpt++ ] );
}
