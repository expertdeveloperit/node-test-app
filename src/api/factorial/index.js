import { Router } from 'express'
import { factorial } from './controller'

const router = new Router()

/**
 * @api {post} /fact Factorial
 * @apiName fact
 * @apiGroup Factorial
 * @apiParam {Number} number who's factorial to be calculated.
 * @apiSuccess (Success 201) {Object} result factorial for the added number.
 */

router.post('/', factorial)

export default router
