/*
 * librdkafka - Apache Kafka C library
 *
 * Copyright (c) 2017 Magnus Edenhill
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @warning THIS FILE WAS AUTOMATICALLY GENERATED BY generate-protocol.py
 *          DO NOT EDIT!
 */


#ifndef _RDKAFKA_PROTO_REQUESTS_H_
#define _RDKAFKA_PROTO_REQUESTS_H_

/**
 * @brief Apache Kafka protocol requests
 */
typedef enum {
#define RD_KAFKAP_None -1
        RD_KAFKAP_Produce = 0,
        RD_KAFKAP_Fetch = 1,
        RD_KAFKAP_ListOffset = 2,
        RD_KAFKAP_Metadata = 3,
        RD_KAFKAP_LeaderAndIsr = 4,
        RD_KAFKAP_StopReplica = 5,
        RD_KAFKAP_UpdateMetadata = 6,
        RD_KAFKAP_ControlledShutdown = 7,
        RD_KAFKAP_OffsetCommit = 8,
        RD_KAFKAP_OffsetFetch = 9,
        RD_KAFKAP_FindCoordinator = 10,
        RD_KAFKAP_JoinGroup = 11,
        RD_KAFKAP_Heartbeat = 12,
        RD_KAFKAP_LeaveGroup = 13,
        RD_KAFKAP_SyncGroup = 14,
        RD_KAFKAP_DescribeGroups = 15,
        RD_KAFKAP_ListGroups = 16,
        RD_KAFKAP_SaslHandshake = 17,
        RD_KAFKAP_ApiVersions = 18,
        RD_KAFKAP_CreateTopics = 19,
        RD_KAFKAP_DeleteTopics = 20,
        RD_KAFKAP_DeleteRecords = 21,
        RD_KAFKAP_InitProducerId = 22,
        RD_KAFKAP_OffsetForLeaderEpoch = 23,
        RD_KAFKAP_AddPartitionsToTxn = 24,
        RD_KAFKAP_AddOffsetsToTxn = 25,
        RD_KAFKAP_EndTxn = 26,
        RD_KAFKAP_WriteTxnMarkers = 27,
        RD_KAFKAP_TxnOffsetCommit = 28,
        RD_KAFKAP_DescribeAcls = 29,
        RD_KAFKAP_CreateAcls = 30,
        RD_KAFKAP_DeleteAcls = 31,
        RD_KAFKAP_DescribeConfigs = 32,
        RD_KAFKAP_AlterConfigs = 33,
        RD_KAFKAP_AlterReplicaLogDirs = 34,
        RD_KAFKAP_DescribeLogDirs = 35,
        RD_KAFKAP_SaslAuthenticate = 36,
        RD_KAFKAP_CreatePartitions = 37,
        RD_KAFKAP_CreateDelegationToken = 38,
        RD_KAFKAP_RenewDelegationToken = 39,
        RD_KAFKAP_ExpireDelegationToken = 40,
        RD_KAFKAP_DescribeDelegationToken = 41,
        RD_KAFKAP_DeleteGroups = 42,
        RD_KAFKAP_ElectLeaders = 43,
        RD_KAFKAP_IncrementalAlterConfigs = 44,
        RD_KAFKAP_AlterPartitionReassignments = 45,
        RD_KAFKAP_ListPartitionReassignments = 46,
        RD_KAFKAP_OffsetDelete = 47,
#define RD_KAFKAP__CNT (RD_KAFKAP_OffsetDelete+1)

} rd_kafkap_request_type_t;


/**
 * @brief Protocol field types
 */
typedef enum {
        RD_KAFKAP_FIELD_TYPE_INVALID,
        RD_KAFKAP_FIELD_TYPE_ROOT,
        RD_KAFKAP_FIELD_TYPE_INT8,
        RD_KAFKAP_FIELD_TYPE_INT16,
        RD_KAFKAP_FIELD_TYPE_INT32,
        RD_KAFKAP_FIELD_TYPE_INT64,
        RD_KAFKAP_FIELD_TYPE_BOOL,
        RD_KAFKAP_FIELD_TYPE_STR,
        RD_KAFKAP_FIELD_TYPE_BYTES,
        RD_KAFKAP_FIELD_TYPE_ARRAY,

        RD_KAFKAP_FIELD_TYPE__CNT
} rd_kafkap_field_type_t;

/**
 * @returns the human readable name for a field type
 */
static RD_UNUSED const char *
rd_kafkap_field_type2str (rd_kafkap_field_type_t ftype) {
        static const char *names[] = {
                "invalid",
                "root",
                "int8",
                "int16",
                "int32",
                "int64",
                "bool",
                "string",
                "bytes",
                "array"
        };

        rd_assert(ftype >= 0 && ftype < RD_KAFKAP_FIELD_TYPE__CNT);
        return names[ftype];
}


/**
 * @brief Protoco field
 */
typedef struct rd_kafkap_field_s {
        const char               *name;
        rd_kafkap_field_type_t    ftype;
        rd_bool_t                 nullable;
        size_t                    field_cnt;
        const struct rd_kafkap_field_s *fields[];   /**< Sub-fields */
} rd_kafkap_field_t;

/**
 * @brief Maximum ApiVersion in any request
 */
#define RD_KAFKAP__VERSION_MAX 11


/**
 * @struct An Apache Kafka protocol request or response definition
 */
typedef struct rd_kafkap_request_s {
        int16_t     apiKey;
        const char *name;
        int16_t     minver;
        int16_t     maxver;
        const rd_kafkap_field_t *req_versions[RD_KAFKAP__VERSION_MAX+1]; /**< Request versions */
        const rd_kafkap_field_t *resp_versions[RD_KAFKAP__VERSION_MAX+1]; /**< Response versions */
} rd_kafkap_request_t;

/**< The protocol definition tree */
extern const rd_kafkap_request_t rd_kafkap_requests[RD_KAFKAP__CNT];

#endif /* _RDKAFKA_PROTO_REQUESTS_H_ */