/**
 * @file json/json.h
 * @brief Internal functions for JSON addon.
 */

#include "../../private_api.h"

#ifdef FLECS_JSON

/* Deserialize from JSON */
typedef enum ecs_json_token_t {
    JsonObjectOpen,
    JsonObjectClose,
    JsonArrayOpen,
    JsonArrayClose,
    JsonColon,
    JsonComma,
    JsonNumber,
    JsonString,
    JsonTrue,
    JsonFalse,
    JsonNull,
    JsonInvalid
} ecs_json_token_t;

const char* flecs_json_parse(
    const char *json,
    ecs_json_token_t *token_kind,
    char *token);

const char* flecs_json_expect(
    const char *json,
    ecs_json_token_t token_kind,
    char *token,
    const ecs_from_json_desc_t *desc);

const char* flecs_json_expect_member(
    const char *json,
    char *token,
    const ecs_from_json_desc_t *desc);

const char* flecs_json_expect_member_name(
    const char *json,
    char *token,
    const char *member_name,
    const ecs_from_json_desc_t *desc);

const char* flecs_json_skip_object(
    const char *json,
    char *token,
    const ecs_from_json_desc_t *desc);

const char* flecs_json_skip_array(
    const char *json,
    char *token,
    const ecs_from_json_desc_t *desc);

/* Serialize to JSON */
void flecs_json_next(
    ecs_strbuf_t *buf);

void flecs_json_number(
    ecs_strbuf_t *buf,
    double value);

void flecs_json_true(
    ecs_strbuf_t *buf);

void flecs_json_false(
    ecs_strbuf_t *buf);

void flecs_json_bool(
    ecs_strbuf_t *buf,
    bool value);

void flecs_json_array_push(
    ecs_strbuf_t *buf);

void flecs_json_array_pop(
    ecs_strbuf_t *buf);

void flecs_json_object_push(
    ecs_strbuf_t *buf);

void flecs_json_object_pop(
    ecs_strbuf_t *buf);

void flecs_json_string(
    ecs_strbuf_t *buf,
    const char *value);

void flecs_json_string_escape(
    ecs_strbuf_t *buf,
    const char *value);

void flecs_json_member(
    ecs_strbuf_t *buf,
    const char *name);

void flecs_json_membern(
    ecs_strbuf_t *buf,
    const char *name,
    int32_t name_len);

#define flecs_json_memberl(buf, name)\
    flecs_json_membern(buf, name, sizeof(name) - 1)

void flecs_json_path(
    ecs_strbuf_t *buf,
    const ecs_world_t *world,
    ecs_entity_t e);

void flecs_json_label(
    ecs_strbuf_t *buf,
    const ecs_world_t *world,
    ecs_entity_t e);

void flecs_json_color(
    ecs_strbuf_t *buf,
    const ecs_world_t *world,
    ecs_entity_t e);

void flecs_json_id(
    ecs_strbuf_t *buf,
    const ecs_world_t *world,
    ecs_id_t id);

ecs_primitive_kind_t flecs_json_op_to_primitive_kind(
    ecs_meta_type_op_kind_t kind);

#endif
