/*
 * Libight interface - Public domain.
 * WARNING: Autogenerated file - do not edit!
 */

#ifndef IGHT_WRAPPERS_H
# define IGHT_WRAPPERS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Hooks and slots: */

typedef void (*ight_hook_vo)(void *);
typedef void (*ight_hook_vos)(void *, const char *);

typedef void (*ight_slot_vo)(void *);

struct evbuffer;

/* Classes: */

struct IghtConnection;
struct IghtEchoServer;
struct IghtPollable;
struct IghtPoller;
struct IghtProtocol;
struct IghtStringVector;

/* IghtPoller API: */

struct IghtPoller *IghtPoller_construct(void);

int IghtPoller_sched(struct IghtPoller *, double, ight_hook_vo, void *);

int IghtPoller_defer_read(struct IghtPoller *, long long, ight_hook_vo,
    ight_hook_vo, void *, double);

int IghtPoller_defer_write(struct IghtPoller *, long long, ight_hook_vo,
    ight_hook_vo, void *, double);

int IghtPoller_resolve(struct IghtPoller *, const char *, const char *,
    ight_hook_vos, void *);

void IghtPoller_loop(struct IghtPoller *);

void IghtPoller_break_loop(struct IghtPoller *);

/* IghtStringVector API: */

struct IghtStringVector *IghtStringVector_construct(struct IghtPoller *,
    size_t);

int IghtStringVector_append(struct IghtStringVector *, const char *);

struct IghtPoller *IghtStringVector_get_poller(struct IghtStringVector *);

const char *IghtStringVector_get_next(struct IghtStringVector *);

void IghtStringVector_destruct(struct IghtStringVector *);

/* IghtEchoServer API: */

struct IghtEchoServer *IghtEchoServer_construct(struct IghtPoller *, int,
    const char *, const char *);

/* IghtProtocol API: */

struct IghtProtocol *IghtProtocol_construct(struct IghtPoller *, ight_slot_vo,
    ight_slot_vo, ight_slot_vo, ight_slot_vo, ight_slot_vo, ight_slot_vo,
    void *);

struct IghtPoller *IghtProtocol_get_poller(struct IghtProtocol *);

void IghtProtocol_destruct(struct IghtProtocol *);

/* IghtConnection API: */

struct IghtConnection *IghtConnection_attach(struct IghtProtocol *, long long);

struct IghtConnection *IghtConnection_connect(struct IghtProtocol *,
    const char *, const char *, const char *);

struct IghtConnection *IghtConnection_connect_hostname(struct IghtProtocol *,
    const char *, const char *, const char *);

struct IghtProtocol *IghtConnection_get_protocol(struct IghtConnection *);

int IghtConnection_set_timeout(struct IghtConnection *, double);

int IghtConnection_clear_timeout(struct IghtConnection *);

int IghtConnection_start_tls(struct IghtConnection *, unsigned);

int IghtConnection_read(struct IghtConnection *, char *, size_t);

int IghtConnection_readline(struct IghtConnection *, char *, size_t);

int IghtConnection_readn(struct IghtConnection *, char *, size_t);

int IghtConnection_discardn(struct IghtConnection *, size_t);

int IghtConnection_write(struct IghtConnection *, const char *, size_t);

int IghtConnection_puts(struct IghtConnection *, const char *);

int IghtConnection_write_rand(struct IghtConnection *, size_t);

int IghtConnection_write_readbuf(struct IghtConnection *, const char *, size_t);

int IghtConnection_puts_readbuf(struct IghtConnection *, const char *);

int IghtConnection_write_rand_readbuf(struct IghtConnection *, size_t);

int IghtConnection_read_into_(struct IghtConnection *, struct evbuffer *);

int IghtConnection_write_from_(struct IghtConnection *, struct evbuffer *);

int IghtConnection_enable_read(struct IghtConnection *);

int IghtConnection_disable_read(struct IghtConnection *);

void IghtConnection_close(struct IghtConnection *);

/* IghtPollable API: */

struct IghtPollable *IghtPollable_construct(struct IghtPoller *, ight_slot_vo,
    ight_slot_vo, ight_slot_vo, void *);

int IghtPollable_attach(struct IghtPollable *, long long);

void IghtPollable_detach(struct IghtPollable *);

long long IghtPollable_get_fileno(struct IghtPollable *);

int IghtPollable_set_readable(struct IghtPollable *);

int IghtPollable_unset_readable(struct IghtPollable *);

int IghtPollable_set_writable(struct IghtPollable *);

int IghtPollable_unset_writable(struct IghtPollable *);

void IghtPollable_set_timeout(struct IghtPollable *, double);

void IghtPollable_clear_timeout(struct IghtPollable *);

void IghtPollable_close(struct IghtPollable *);

#ifdef __cplusplus
}
#endif

#endif  /* IGHT_WRAPPERS_H */