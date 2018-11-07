/*$$$LICENCE_NORDIC_STANDARD<2014>$$$*/
#include "ble_struct_serialization.h"
#include "ble_gap_struct_serialization.h"
#include "ble_gatt_struct_serialization.h"
#include "ble_gatts_struct_serialization.h"
#include "ble_serialization.h"
#include "app_util.h"
#include "ble_types.h"
#include "ble.h"
#include "cond_field_serialization.h"
#ifdef SER_CONNECTIVITY
#include "conn_ble_gap_sec_keys.h"
#endif
#include <string.h>


#if !defined(SER_CONNECTIVITY) && NRF_SD_BLE_API_VERSION > 5
#include "app_ble_gap.h"
#endif

uint32_t ble_uuid_t_enc(void const * const p_void_struct,
                        uint8_t * const    p_buf,
                        uint32_t           buf_len,
                        uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_uuid_t);

    SER_PUSH_uint16(&p_struct->uuid);
    SER_PUSH_uint8(&p_struct->type);

    SER_STRUCT_ENC_END;
}

uint32_t ble_uuid_t_dec(uint8_t const * const p_buf,
                        uint32_t              buf_len,
                        uint32_t * const      p_index,
                        void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_uuid_t);

    SER_PULL_uint16(&p_struct->uuid);
    SER_PULL_uint8(&p_struct->type);

    SER_STRUCT_DEC_END;
}

uint32_t ble_uuid128_t_enc(void const * const p_void_struct,
                           uint8_t * const    p_buf,
                           uint32_t           buf_len,
                           uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_uuid128_t);
    SER_PUSH_uint8array(p_struct->uuid128, sizeof (p_struct->uuid128));
    SER_STRUCT_ENC_END;
}

uint32_t ble_uuid128_t_dec(uint8_t const * const p_buf,
                           uint32_t              buf_len,
                           uint32_t * const      p_index,
                           void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_uuid128_t);
    SER_PULL_uint8array(p_struct->uuid128, sizeof (p_struct->uuid128));
    SER_STRUCT_DEC_END;
}

#if defined(NRF_SD_BLE_API_VERSION) && NRF_SD_BLE_API_VERSION < 4
uint32_t ble_enable_params_t_enc(void const * const p_void_struct,
                                 uint8_t * const    p_buf,
                                 uint32_t           buf_len,
                                 uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_enable_params_t);

    SER_PUSH_FIELD(&p_struct->common_enable_params, ble_common_enable_params_t_enc);
    SER_PUSH_FIELD(&p_struct->gap_enable_params, ble_gap_enable_params_t_enc);
    SER_PUSH_FIELD(&p_struct->gatt_enable_params, ble_gatt_enable_params_t_enc);
    SER_PUSH_FIELD(&p_struct->gatts_enable_params, ble_gatts_enable_params_t_enc);

    SER_STRUCT_ENC_END;
}

uint32_t ble_enable_params_t_dec(uint8_t const * const p_buf,
                                 uint32_t              buf_len,
                                 uint32_t * const      p_index,
                                 void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_enable_params_t);

    SER_PULL_FIELD(&p_struct->common_enable_params, ble_common_enable_params_t_dec);
    SER_PULL_FIELD(&p_struct->gap_enable_params, ble_gap_enable_params_t_dec);
    SER_PULL_FIELD(&p_struct->gatt_enable_params, ble_gatt_enable_params_t_dec);
    SER_PULL_FIELD(&p_struct->gatts_enable_params, ble_gatts_enable_params_t_dec);

    SER_STRUCT_DEC_END;
}

uint32_t ble_conn_bw_t_enc(void const * const p_void_struct,
                           uint8_t * const    p_buf,
                           uint32_t           buf_len,
                           uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_conn_bw_t);

    SER_PUSH_uint8(&p_struct->conn_bw_rx);
    SER_PUSH_uint8(&p_struct->conn_bw_tx);

    SER_STRUCT_ENC_END;
}

uint32_t ble_conn_bw_t_dec(uint8_t const * const p_buf,
                           uint32_t              buf_len,
                           uint32_t * const      p_index,
                           void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_conn_bw_t);

    SER_PULL_uint8(&p_struct->conn_bw_rx);
    SER_PULL_uint8(&p_struct->conn_bw_tx);

    SER_STRUCT_DEC_END;
}

uint32_t ble_common_opt_conn_bw_t_enc(void const * const p_void_struct,
                                      uint8_t * const    p_buf,
                                      uint32_t           buf_len,
                                      uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_common_opt_conn_bw_t);

    SER_PUSH_uint8(&p_struct->role);
    SER_PUSH_FIELD(&p_struct->conn_bw, ble_conn_bw_t_enc);

    SER_STRUCT_ENC_END;
}

uint32_t ble_common_opt_conn_bw_t_dec(uint8_t const * const p_buf,
                                      uint32_t              buf_len,
                                      uint32_t * const      p_index,
                                      void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_common_opt_conn_bw_t);

    SER_PULL_uint8(&p_struct->role);
    SER_PULL_FIELD(&p_struct->conn_bw, ble_conn_bw_t_dec);

    SER_STRUCT_DEC_END;
}

uint32_t ble_conn_bw_count_t_enc(void const * const p_void_struct,
                                 uint8_t * const    p_buf,
                                 uint32_t           buf_len,
                                 uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_conn_bw_count_t);

    SER_PUSH_uint8(&p_struct->high_count);
    SER_PUSH_uint8(&p_struct->mid_count);
    SER_PUSH_uint8(&p_struct->low_count);

    SER_STRUCT_DEC_END;
}

uint32_t ble_conn_bw_count_t_dec(uint8_t const * const p_buf,
                                 uint32_t              buf_len,
                                 uint32_t * const      p_index,
                                 void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_conn_bw_count_t);

    SER_PULL_uint8(&p_struct->high_count);
    SER_PULL_uint8(&p_struct->mid_count);
    SER_PULL_uint8(&p_struct->low_count);

    SER_STRUCT_DEC_END;
}

uint32_t ble_conn_bw_counts_t_enc(void const * const p_void_struct,
                                  uint8_t * const    p_buf,
                                  uint32_t           buf_len,
                                  uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_conn_bw_counts_t);

    SER_PUSH_FIELD(&p_struct->tx_counts, ble_conn_bw_count_t_enc);
    SER_PUSH_FIELD(&p_struct->rx_counts, ble_conn_bw_count_t_enc);

    SER_STRUCT_DEC_END;
}

uint32_t ble_conn_bw_counts_t_dec(uint8_t const * const p_buf,
                                  uint32_t              buf_len,
                                  uint32_t * const      p_index,
                                  void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_conn_bw_counts_t);

    SER_PULL_FIELD(&p_struct->tx_counts, ble_conn_bw_count_t_dec);
    SER_PULL_FIELD(&p_struct->rx_counts, ble_conn_bw_count_t_dec);

    SER_STRUCT_DEC_END;
}

uint32_t ble_common_enable_params_t_enc(void const * const p_void_struct,
                                        uint8_t * const    p_buf,
                                        uint32_t           buf_len,
                                        uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_common_enable_params_t);

    SER_PUSH_uint16(&p_struct->vs_uuid_count);
    SER_PUSH_COND(p_struct->p_conn_bw_counts, ble_conn_bw_counts_t_enc);

    SER_STRUCT_ENC_END;
}

uint32_t ble_common_enable_params_t_dec(uint8_t const * const p_buf,
                                        uint32_t              buf_len,
                                        uint32_t * const      p_index,
                                        void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_common_enable_params_t);

    SER_PULL_uint16(&p_struct->vs_uuid_count);
    SER_PULL_COND(&p_struct->p_conn_bw_counts, ble_conn_bw_counts_t_dec);

    SER_STRUCT_DEC_END;
}
#endif
uint32_t ble_common_opt_pa_lna_t_enc(void const * const p_void_struct,
                                 uint8_t * const    p_buf,
                                 uint32_t           buf_len,
                                 uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_common_opt_pa_lna_t);

    SER_PUSH_FIELD(&p_struct->pa_cfg, ble_pa_lna_cfg_t_enc);
    SER_PUSH_FIELD(&p_struct->lna_cfg, ble_pa_lna_cfg_t_enc);
    SER_PUSH_uint8(&p_struct->ppi_ch_id_set);
    SER_PUSH_uint8(&p_struct->ppi_ch_id_clr);
    SER_PUSH_uint8(&p_struct->gpiote_ch_id);

    SER_STRUCT_ENC_END;
}

uint32_t ble_common_opt_pa_lna_t_dec(uint8_t const * const p_buf,
                                      uint32_t              buf_len,
                                      uint32_t * const      p_index,
                                      void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_common_opt_pa_lna_t);

    SER_PULL_FIELD(&p_struct->pa_cfg, ble_pa_lna_cfg_t_dec);
    SER_PULL_FIELD(&p_struct->lna_cfg, ble_pa_lna_cfg_t_dec);
    SER_PULL_uint8(&p_struct->ppi_ch_id_set);
    SER_PULL_uint8(&p_struct->ppi_ch_id_clr);
    SER_PULL_uint8(&p_struct->gpiote_ch_id);

    SER_STRUCT_DEC_END;
}


uint32_t ble_pa_lna_cfg_t_enc(void const * const p_void_struct,
                              uint8_t * const    p_buf,
                              uint32_t           buf_len,
                              uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_pa_lna_cfg_t);

    uint8_t ser_data = (p_struct->enable & 0x01)
                       | ((p_struct->active_high & 0x01) << 1)
                       | ((p_struct->gpio_pin    & 0x3F) << 2);
    SER_PUSH_uint8(&ser_data);

    SER_STRUCT_ENC_END;
}

uint32_t ble_pa_lna_cfg_t_dec(uint8_t const * const p_buf,
                              uint32_t              buf_len,
                              uint32_t * const      p_index,
                              void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_pa_lna_cfg_t);

    uint8_t ser_data;
    SER_PULL_uint8(&ser_data);
    p_struct->enable      = ser_data & 0x01;
    p_struct->active_high = (ser_data >> 1) & 0x01;
    p_struct->gpio_pin    = (ser_data >> 2) & 0x3F;

    SER_STRUCT_DEC_END;
}


uint32_t ble_user_mem_block_t_enc(void const * const p_void_struct,
                                  uint8_t * const    p_buf,
                                  uint32_t           buf_len,
                                  uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_user_mem_block_t);

    SER_PUSH_uint16(&p_struct->len);
    SER_PUSH_COND(p_struct->p_mem, NULL);

    SER_STRUCT_ENC_END;
}

uint32_t ble_user_mem_block_t_dec(uint8_t const * const p_buf,
                                  uint32_t              buf_len,
                                  uint32_t * const      p_index,
                                  void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_user_mem_block_t);

    SER_PULL_uint16(&p_struct->len);
    SER_PULL_COND(&p_struct->p_mem, NULL);

    SER_STRUCT_DEC_END;
}

uint32_t ble_version_t_enc(void const * const p_void_struct,
                           uint8_t * const    p_buf,
                           uint32_t           buf_len,
                           uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_version_t);

    SER_PUSH_uint8(&p_struct->version_number);
    SER_PUSH_uint16(&p_struct->company_id);
    SER_PUSH_uint16(&p_struct->subversion_number);

    SER_STRUCT_ENC_END;
}

uint32_t ble_version_t_dec(uint8_t const * const p_buf,
                           uint32_t              buf_len,
                           uint32_t * const      p_index,
                           void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_version_t);

    SER_PULL_uint8(&p_struct->version_number);
    SER_PULL_uint16(&p_struct->company_id);
    SER_PULL_uint16(&p_struct->subversion_number);

    SER_STRUCT_DEC_END;
}
#if defined(NRF_SD_BLE_API_VERSION) && NRF_SD_BLE_API_VERSION < 4
uint32_t ble_evt_data_length_changed_t_enc(void const * const p_void_struct,
                                           uint8_t * const    p_buf,
                                           uint32_t           buf_len,
                                           uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_evt_data_length_changed_t);

    SER_PUSH_uint16(&p_struct->max_tx_octets);
    SER_PUSH_uint16(&p_struct->max_tx_time);
    SER_PUSH_uint16(&p_struct->max_rx_octets);
    SER_PUSH_uint16(&p_struct->max_rx_time);

    SER_STRUCT_ENC_END;
}

uint32_t ble_evt_data_length_changed_t_dec(uint8_t const * const p_buf,
                                           uint32_t              buf_len,
                                           uint32_t * const      p_index,
                                           void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_evt_data_length_changed_t);

    SER_PULL_uint16(&p_struct->max_tx_octets);
    SER_PULL_uint16(&p_struct->max_tx_time);
    SER_PULL_uint16(&p_struct->max_rx_octets);
    SER_PULL_uint16(&p_struct->max_rx_time);

    SER_STRUCT_DEC_END;
}
#endif
uint32_t ble_common_opt_conn_evt_ext_t_enc(void const * const p_void_struct,
                                           uint8_t * const    p_buf,
                                           uint32_t           buf_len,
                                           uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_common_opt_conn_evt_ext_t);

    uint8_t  ser_data = p_struct->enable & 0x01;
    SER_PUSH_uint8(&ser_data);

    SER_STRUCT_ENC_END;
}

uint32_t ble_common_opt_conn_evt_ext_t_dec(uint8_t const * const p_buf,
                                           uint32_t              buf_len,
                                           uint32_t * const      p_index,
                                           void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_common_opt_conn_evt_ext_t);

    uint8_t ser_data;
    SER_PULL_uint8(&ser_data);
    p_struct->enable = ser_data & 0x01;

    SER_STRUCT_DEC_END;
}
#if NRF_SD_BLE_API_VERSION >= 4
uint32_t ble_common_cfg_vs_uuid_t_enc(void const * const p_void_struct,
                                           uint8_t * const    p_buf,
                                           uint32_t           buf_len,
                                           uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_common_cfg_vs_uuid_t);

    SER_PUSH_uint8(&p_struct->vs_uuid_count);

    SER_STRUCT_ENC_END;
}

uint32_t ble_common_cfg_vs_uuid_t_dec(uint8_t const * const p_buf,
                                           uint32_t              buf_len,
                                           uint32_t * const      p_index,
                                           void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_common_cfg_vs_uuid_t);

    SER_PULL_uint8(&p_struct->vs_uuid_count);

    SER_STRUCT_DEC_END;
}

#endif

#if defined(NRF_SD_BLE_API_VERSION) && NRF_SD_BLE_API_VERSION > 4
uint32_t ble_data_t_enc(void const * const p_void_struct,
                        uint8_t * const    p_buf,
                        uint32_t           buf_len,
                        uint32_t * const   p_index)
{
    SER_STRUCT_ENC_BEGIN(ble_data_t);
    uint32_t buf_id = 0;

#if NRF_SD_BLE_API_VERSION > 5
#if defined(SER_CONNECTIVITY)
    conn_ble_gap_ble_data_buf_free(p_struct->p_data);
#else
    buf_id = app_ble_gap_adv_buf_register(p_struct->p_data);
#endif
#endif

    SER_PUSH_uint32(&buf_id);
    SER_PUSH_len16data(p_struct->p_data, p_struct->len);

    SER_STRUCT_ENC_END;
}

uint32_t ble_data_t_dec(uint8_t const * const p_buf,
                        uint32_t              buf_len,
                        uint32_t * const      p_index,
                        void * const          p_void_struct)
{
    SER_STRUCT_DEC_BEGIN(ble_data_t);

    uint32_t buf_id;
    SER_PULL_uint32(&buf_id);
#if NRF_SD_BLE_API_VERSION > 5
#if defined(SER_CONNECTIVITY)
     if (buf_id)
     {
         p_struct->p_data = conn_ble_gap_ble_data_buf_alloc(buf_id);
     }
#else
    p_struct->p_data = app_ble_gap_adv_buf_unregister(buf_id);
#endif
#endif

    p_struct->len = 1024;
    SER_PULL_len16data(&p_struct->p_data, &p_struct->len);

    SER_STRUCT_DEC_END;
}
#endif
