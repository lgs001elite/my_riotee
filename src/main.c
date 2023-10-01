#include "riotee.h"
#include "riotee_stella.h"
#include "riotee_timing.h"

const char adv_name[] = "RIOTEE";
const uint8_t hop_id = 1;
const uint8_t device_id = 1;
riotee_stella_pkt_t *rx_pkt;
riotee_stella_pkt_t *tx_pkt;
uint8_t packets_counter = 0;
uint8_t match_id = 0;
uint8_t counter = 0;
uint64_t before_tick = 0;
uint64_t *calculate_tick = 0;
uint8_t sleepTime; // ms

void reset_callback(void)
{
  riotee_stella_init();
}

/* This callback is called when the capacitor voltage drops below a threshold */
void suspend_callback(void)
{
  before_tick = riotee_timing_now(calculate_tick);
}

/* This callback is called when the capacitor voltage has recovered and the application resumes. */
void resume_callback(void)
{
  sleepTime = (*calculate_tick - before_tick) * 1000 / 33; // us
}

int main()
{
  tx_pkt->len = 255;
  tx_pkt->hdr.dev_id = 0x01;
  tx_pkt->hdr.pkt_id = counter;
  tx_pkt->hdr.ack_id = 0;
  tx_pkt->hdr.match_id = match_id;
  tx_pkt->hdr.hop_id = hop_id;
  for (;;)
  {
    riotee_wait_cap_charged();
    riotee_stella_transceive(rx_pkt, tx_pkt);
    tx_pkt->hdr.ack_id = 0;
    if (rx_pkt != NULL)
    {
      if ((rx_pkt->hdr.hop_id < hop_id) && (rx_pkt->hdr.ack_id == 0))
      {
        tx_pkt->hdr.ack_id = 0x01;
        packets_counter = packets_counter + 1;
      }
      if ((rx_pkt->hdr.dev_id == device_id) && (rx_pkt->hdr.pkt_id == counter) && (rx_pkt->hdr.ack_id == 0x01))
      {
        match_id = rx_pkt->hdr.match_id;
        counter++;
      }
    }
    riotee_sleep_ms(1000);
  }
}
