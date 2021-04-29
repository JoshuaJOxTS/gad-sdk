#ifndef GAD_ENCODER_CSV_HPP
#define GAD_ENCODER_CSV_HPP
/** @file gad_encoder_csv.hpp */

#include "oxts/gal-cpp/gad_encoders/gad_encoder.hpp"


namespace OxTS
{

/**
 * Wrapper for C Generic Aiding csv encoding functionality.
 * 
 * @todo Implement this csv encoding wrapper.
 */
class GadEncoderCsv : public GadEncoder
{

private:
  inline void EncodeGadCsv(Gad& g)
  {
    GEN_AIDING_DATA genaid = g.getCStruct();
    encode_gad_to_csv(this->out_string,offset_ptr, &genaid);
  }

  char * out_string;
  int offset;
  int * offset_ptr;
public:

  /** Constructor */
  GadEncoderCsv()
  {
    offset = 0;
    this->offset_ptr = &offset;
    this->buffer_offset = 0;
    this->gad_size = 0;
    this->out_string = (char *)malloc(MAX_BUFF);
  }

  /** Encode the generic aiding packet to csv format.
   * @param g Reference to the Gad data to be encoded.
   */
  void EncodePacket(Gad& g) override
  {
    memset(this->buffer, 0, MAX_BUFF);    // Clear buffer
    this->offset = 0;                     // Set offset to 0
    EncodeGadCsv(g);                      // Encode Gad
  }
  /** Retrieve the encoded packet 
   * @return Char array containing the packet encoded in csv form.
  */
  auto GetPacket() -> unsigned char * override
  {
    return reinterpret_cast<unsigned char *>(this->out_string);
  }
  /** 
   * @return The encoded packet size (bytes)
  */
  auto GetPacketSize() -> std::size_t override 
  {
    return this->offset;
  }

};

}


#endif // GAD_ENCODER_CSV_HPP